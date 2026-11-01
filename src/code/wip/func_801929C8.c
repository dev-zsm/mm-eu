#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad3[5];
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ u8 pad10[0x14];
    /* 0x24 */ u8 unk24[0x18];
    /* 0x3C */ u8 unk3C[4];
    /* 0x40 */ u8 unk40[4];
} Dma;

extern u8 D_801D7BE4[];
extern void Audio_InvalDCache(s32, s32);
extern void func_8008F3E0(void *, void *, s32);
extern void func_8019155C(void *, s32, s32, s32, s32, s32, void *, s32, void *);

void AudioLoad_AsyncDma(Dma *a0, s32 a1) {
    u8 *q;
    s32 size = (a1 + 0xF) & ~0xF;

    Audio_InvalDCache(a0->unkC, size);
    q = a0->unk24;
    func_8008F3E0(q, a0->unk3C, 1);
    func_8019155C(a0->unk40, 0, 0, a0->unk8, a0->unkC, size, q, a0->unk2, D_801D7BE4);
}
