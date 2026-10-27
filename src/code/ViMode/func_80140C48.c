#include "types.h"

typedef struct {
    u8 pad0[0x50];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
} VideoState;

extern s32 D_80000300;

extern void ViMode_Save(VideoState *state);

void ViMode_Init(VideoState *state) {
    state->unk68 = 0;
    state->unk54 = 0x140;
    state->unk50 = 0xF0;
    state->unk5C = 0;
    state->unk58 = 0;
    state->unk64 = 0;
    state->unk60 = 0;
    state->unk80 = 0x42;
    state->unk6C = D_80000300;
    state->unk7C = 1;
    state->unk78 = 1;
    state->unk74 = 0;
    state->unk70 = 1;
    ViMode_Save(state);
}
