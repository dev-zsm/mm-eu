#include "types.h"

typedef struct {
    /* 0x00000 */ u8 pad0[0x12024];
    /* 0x12024 */ u8 unk12024;
} MessageContext;

typedef struct {
    /* 0x00000 */ u8 pad0[0x20];
    /* 0x00020 */ u16 pressButton;
    /* 0x00022 */ u8 pad22[0x48E6];
    /* 0x04908 */ MessageContext msgCtx;
} PlayState;

/* returns whether button 0x8000 (or, outside modes 0x10/0x11, 0x4000 or 8) is pressed */
s32 func_80147C44(PlayState *play) {
    MessageContext *msgCtx = &play->msgCtx;

    if ((msgCtx->unk12024 == 0x10) || (msgCtx->unk12024 == 0x11)) {
        return ~(play->pressButton | ~0x8000) == 0;
    }
    return (~(play->pressButton | ~0x8000) == 0) || (~(play->pressButton | ~0x4000) == 0) ||
           (~(play->pressButton | ~8) == 0);
}
