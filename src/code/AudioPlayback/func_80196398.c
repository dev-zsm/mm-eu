// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 count;
    u8 pad1[7];
    void **table;
    u8 pad0C[8];
} InstSet;

typedef struct {
    u8 pad0[0x2868];
    InstSet *sets;
    u8 pad286C[0x134];
    s32 error;
} AudioCtx;

extern AudioCtx D_801F84B0;
extern s32 AudioLoad_IsFontLoadComplete(s32, s32);

void *AudioPlayback_GetInstrumentInner(s32 a0, s32 a1) {
    InstSet *set;
    void *p;

    if (a0 == 0xFF) {
        return 0;
    }
    if (!AudioLoad_IsFontLoadComplete(a0, a1)) {
        D_801F84B0.error = a0 + 0x10000000;
        return 0;
    }
    set = (InstSet *)((u8 *)D_801F84B0.sets + a0 * 0x14); // byte-offset form matches the ROM scheduling
    if (a1 >= set->count) {
        D_801F84B0.error = (a0 << 8) + a1 + 0x03000000;
        return 0;
    }
    p = set->table[a1];
    if (p == 0) {
        D_801F84B0.error = (a0 << 8) + a1 + 0x01000000;
        return p;
    }
    return p;
}
