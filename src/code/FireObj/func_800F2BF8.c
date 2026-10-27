#include "types.h"

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    u8 pad10[4];
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    u8 unk24;
} FireObj;

void FireObj_SetState(FireObj *fire, f32 dynamicSizeStep, u8 state) {
    s32 newState = state & 0xFF; // redundant mask kept: the ROM re-extracts the byte after the parameter conversion

    fire->unk24 = state;
    if (newState == 3) {
        fire->unk1C = fire->unk14 = fire->unk18 = 0.0f;
    } else if (newState == 2) {
        fire->unk14 = fire->unk18 = fire->unkC;
        fire->unk1C = 1.0f;
    }
    fire->unk20 = dynamicSizeStep;
}
