// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u32 w0; u32 w1; } Gfx;
typedef struct { u8 pad0[4]; Gfx *dl; u8 pad8[8]; u8 unk10; u8 unk11; u8 unk12; u8 unk13; } Struct;
void func_80085A2C(Struct *s, s32 a1, s32 a2, s32 a3, s32 a4) {
    Gfx *dl;
    s->unk10 = a1; s->unk11 = a2; s->unk12 = a3; s->unk13 = a4;
    dl = s->dl++; dl->w0 = 0xE7000000; dl->w1 = 0;
    dl = s->dl++; dl->w0 = 0xFA000000; dl->w1 = *(u32 *)&s->unk10;
}
