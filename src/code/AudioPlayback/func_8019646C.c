// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[1];
    u8 numDrums;
    u8 pad2[0xA];
    u32 *drums;
    u8 pad10[4];
} DrumBank;

typedef struct {
    u8 pad0[0x2868];
    DrumBank *banks;
    u8 pad286C[0x29A0 - 0x286C];
    s32 errorCode;
} AudioCtx;

extern AudioCtx D_801F84B0;
extern s32 AudioLoad_IsFontLoadComplete(s32 a);

s32 AudioPlayback_GetDrum(s32 bank, s32 drum) {
    DrumBank *b;
    u32 *p;
    s32 ret;

    if (0xFF == bank) {
        return 0;
    }
    if (AudioLoad_IsFontLoadComplete(bank) == 0) {
        D_801F84B0.errorCode = bank + 0x10000000;
        return 0;
    }
    b = (DrumBank *)((s32)D_801F84B0.banks + bank * 0x14);
    if (drum >= b->numDrums) {
        D_801F84B0.errorCode = (bank << 8) + drum + 0x04000000;
        return 0;
    }
    p = b->drums;
    if ((u32)p < 0x80000000) {
        return 0;
    }
    ret = p[drum];
    if (ret == 0) {
        D_801F84B0.errorCode = (bank << 8) + drum + 0x05000000;
    }
    return ret;
}
