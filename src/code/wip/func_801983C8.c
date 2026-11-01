#include "types.h"

typedef struct {
    /* 0x00 */ u8* pc;
    /* 0x04 */ u8* stack[4];
    /* 0x14 */ u8 loopCount[4];
    /* 0x18 */ u8 depth;
    /* 0x19 */ s8 state;
} ScriptState;

typedef struct {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ u8* scriptBase;
} ScriptOwner;

s32 AudioScript_ScriptReadCompressedU16(ScriptState* state);

s32 AudioScript_HandleScriptFlowControl(ScriptOwner* owner, ScriptState* state, s32 cmd, s32 arg) {
    u8 depth;
    u8 idx;

    switch (cmd) {
        case 0xFF:
            if (state->depth == 0) {
                return -1;
            }
            idx = state->depth - 1;
            state->depth = idx;
            state->pc = state->stack[idx];
            break;
        case 0xFD:
            return AudioScript_ScriptReadCompressedU16(state);
        case 0xFE:
            return 1;
        case 0xFC:
            depth = state->depth;
            state->stack[depth] = state->pc;
            state->depth++;
            state->pc = owner->scriptBase + (u16)arg;
            break;
        case 0xF8:
            depth = state->depth;
            state->loopCount[depth] = arg;
            state->stack[state->depth] = state->pc;
            state->depth++;
            break;
        case 0xF7:
            state->loopCount[state->depth - 1]--;
            if (state->loopCount[state->depth - 1] != 0) {
                state->pc = state->stack[state->depth - 1];
            } else {
                state->depth--;
            }
            break;
        case 0xF6:
            state->depth--;
            break;
        case 0xF5:
        case 0xF9:
        case 0xFA:
        case 0xFB:
            if (!(((cmd == 0xFA) && (state->state != 0)) || ((cmd == 0xF9) && (state->state >= 0)) ||
                  ((cmd == 0xF5) && (state->state < 0)))) {
                state->pc = owner->scriptBase + (u16)arg;
            }
            break;
        case 0xF2:
        case 0xF3:
        case 0xF4:
            if (!(((cmd == 0xF3) && (state->state != 0)) || ((cmd == 0xF2) && (state->state >= 0)))) {
                state->pc += (s8)arg;
            }
            break;
    }
    return 0;
}
