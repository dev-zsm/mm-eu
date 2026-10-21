// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[4];
    Gfx *unk4;
    u16 unk8;
    u16 unkA;
    u8 padC[3];
    u8 unkF;
    s32 unk10;
} Struct;

void func_80085AD8(Struct *s, u8 a1) {
    Gfx *dl;
    u32 t;

    if (s->unkF & 8) {
        dl = s->unk4;
        s->unkF = s->unkF & 0xFFF7;
        s->unk4 = dl + 1;
        dl->w1 = 0;
        dl->w0 = 0xE7000000;
        if (s->unkF & 2) {
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w0 = 0xE3001001;
            dl->w1 = 0x8000;
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w0 = 0xE3000A01;
            dl->w1 = 0x100000;
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w0 = 0xE200001C;
            dl->w1 = 0x0C184240;
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w0 = 0xFC1115FF;
            dl->w1 = -0x1C8;
        } else {
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w0 = 0xE3001001;
            dl->w1 = 0xC000;
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w1 = 0;
            dl->w0 = 0xE3000A01;
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w0 = 0xE200001C;
            dl->w1 = 0x504240;
            dl = s->unk4;
            s->unk4 = dl + 1;
            dl->w0 = 0xFC11FE23;
            dl->w1 = -0xC07;
        }
    }
    if (s->unkF & 4) {
        dl = s->unk4;
        s->unk4 = dl + 1;
        dl->w1 = 0;
        dl->w0 = 0xFA000000;
        dl = s->unk4;
        s->unk4 = dl + 1;
        dl->w0 = (((s->unk8 + 0x24) & 0xFFF) << 12) | 0xE4000000 | ((s->unkA + 0x24) & 0xFFF);
        dl->w1 = (((a1 * 2) & 7) << 24) | (((s->unk8 + 4) & 0xFFF) << 12) | ((s->unkA + 4) & 0xFFF);
        dl = s->unk4;
        s->unk4 = dl + 1;
        dl->w0 = 0xE1000000;
        dl->w1 = ((a1 & 4) << 22) | (((a1 >> 3) << 8) & 0xFFFF);
        dl = s->unk4;
        s->unk4 = dl + 1;
        dl->w1 = 0x04000400;
        dl->w0 = 0xF1000000;
        dl = s->unk4;
        s->unk4 = dl + 1;
        dl->w0 = 0xFA000000;
        dl->w1 = s->unk10;
    }
    t = ((a1 & 4) << 22) | (((a1 >> 3) << 8) & 0xFFFF);
    dl = s->unk4;
    s->unk4 = dl + 1;
    dl->w0 = (((s->unk8 + 0x20) & 0xFFF) << 12) | 0xE4000000 | ((s->unkA + 0x20) & 0xFFF);
    dl->w1 = (((a1 * 2) & 7) << 24) | ((s->unk8 & 0xFFF) << 12) | (s->unkA & 0xFFF);
    dl = s->unk4;
    s->unk4 = dl + 1;
    dl->w0 = 0xE1000000;
    dl->w1 = t;
    dl = s->unk4;
    s->unk4 = dl + 1;
    dl->w0 = 0xF1000000;
    dl->w1 = 0x04000400;
    s->unk8 = s->unk8 + 0x20;
}
