// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 pad4[8];
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 pad1A[2];
} ReverbItem; /* size 0x1C */

typedef struct {
    /* 0x00 */ u8 pad0[3];
    /* 0x03 */ u8 curFrame;
    /* 0x04 */ u8 downsample;
    /* 0x05 */ u8 pad5;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u8 pad8[0x14 - 8];
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u8 pad16[2];
    /* 0x18 */ u8 unk18;
    /* 0x19 */ s8 unk19;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u8 pad1E[2];
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x40 - 0x24];
    /* 0x40 */ ReverbItem items[2][5];
    /* 0x158 */ ReverbItem items2[2][5];
    /* 0x270 */ u8 pad270[0x2B8 - 0x270];
} ReverbSub; /* size 0x2B8 */

typedef struct {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ ReverbSub s;
} Reverb; /* size 0x2D0 */

extern Reverb D_801F84B0[];

void func_801886B0(s32 arg0, s32 arg1, s32 arg2) {
    Reverb *r;
    ReverbSub *s;
    ReverbItem *item;
    ReverbItem *item2;
    s32 v1;
    s32 a2;
    s32 t1;
    s32 lo;
    s32 a3;
    s32 hi;
    s32 v;
    u32 ratio;
    u16 t2;

    r = &D_801F84B0[arg2];
    item = &r->s.items[r->s.curFrame][arg1];
    v1 = arg0 / r->s.downsample;
    s = &r->s;
    if (s->unk18 != 0) {
        a2 = 0;
        if (s->downsample == 1) {
            t1 = 0;
            v1 += s->unk19;
            t2 = v1;
            item->unk18 = v1;
            item->unk14 = (t2 << 15) / arg0;
            item->unk16 = (arg0 << 15) / t2;
            for (;;) {
                ratio = item->unk14;
                v = (ratio * arg0 * 2) + s->unk1A;
                hi = v >> 16;
                if (v1 != hi && a2 == 0) {
                    item->unk14 = ((v1 << 16) - s->unk1A) / (arg0 * 2);
                    a2++;
                    continue;
                }
                a2++;
                if (v1 < hi) {
                    item->unk14 = ratio - 1;
                    continue;
                }
                if (hi < v1) {
                    item->unk14 = ratio + 1;
                    continue;
                }
                s->unk1A = v;
                break;
            }
            for (;;) {
                ratio = item->unk16;
                v = (ratio * v1 * 2) + s->unk1C;
                hi = v >> 16;
                if (arg0 != hi && t1 == 0) {
                    item->unk16 = ((arg0 << 16) - s->unk1C) / (v1 * 2);
                    t1++;
                    continue;
                }
                t1++;
                if (arg0 < hi) {
                    item->unk16 = ratio - 1;
                    continue;
                }
                if (hi < arg0) {
                    item->unk16 = ratio + 1;
                    continue;
                }
                s->unk1C = v;
                break;
            }
        }
    }
    s = &r->s;
    t1 = s->unk20;
    a2 = t1 + v1 - s->unk6;
    if (a2 < 0) {
        item->unk10 = v1 * 2;
        item->unk12 = 0;
        item->unkC = s->unk20;
        s->unk20 = s->unk20 + v1;
    } else {
        item->unk10 = (v1 - a2) * 2;
        item->unk12 = a2 * 2;
        item->unkC = s->unk20;
        s->unk20 = a2;
    }
    item->unk0 = v1;
    item->unk2 = arg0;
    a2 = s->unk14;
    if (a2 != 0) {
        t2 = s->unk6;
        a3 = a2 + t1;
        if (a3 >= t2) {
            a3 -= t2;
        }
        lo = arg0 / s->downsample;
        a2 = a3 + lo - t2;
        item2 = &s->items2[s->curFrame][arg1];
        if (a2 < 0) {
            item2->unk10 = lo * 2;
            item2->unk12 = 0;
        } else {
            item2->unk10 = (lo - a2) * 2;
            item2->unk12 = a2 * 2;
        }
        item2->unkC = a3;
        item2->unk0 = lo;
        item2->unk2 = arg0;
    }
}
