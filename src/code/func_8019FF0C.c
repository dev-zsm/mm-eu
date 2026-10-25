// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    /* 0x0 */ f32 unk0;
    /* 0x4 */ f32 unk4;
    /* 0x8 */ u8 unk8;
    /* 0x9 */ u8 unk9;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 unkB;
    /* 0xC */ u8 unkC;
    /* 0xD */ u8 unkD;
    /* 0xE */ u8 padE[2];
} SfxChannelState; // size = 0x10

extern SfxChannelState D_801F4AE8[16];
extern u8 D_801CEFEC;
extern u8 D_801CEFF0;

void AudioSfx_ResetSfxChannelState(void) {
    u8 i;

    for (i = 0; i < 16; i++) {
        D_801F4AE8[i].unk0 = 1.0f;
        D_801F4AE8[i].unk4 = 1.0f;
        D_801F4AE8[i].unk8 = 0;
        D_801F4AE8[i].unk9 = 0x40;
        D_801F4AE8[i].unkA = 0;
        D_801F4AE8[i].unkB = 0xFF;
        D_801F4AE8[i].unkC = 0xFF;
        D_801F4AE8[i].unkD = 0xFF;
    }
    D_801F4AE8[13].unkC = 0;
    D_801CEFF0 = 0;
    D_801CEFEC = 0;
}
