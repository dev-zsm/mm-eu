// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[8];
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u8 unkE;
    u8 unkF;
} Struct;

extern void GfxPrint_PrintCharImpl(Struct *s, s32 a1);

void GfxPrint_PrintChar(Struct *s, u8 a1) {
    s32 v;

    v = a1;
    if (v == 0x20) {
        s->unk8 = s->unk8 + 0x20;
        return;
    }
    if (v >= 0x21 && v < 0x7F) {
        GfxPrint_PrintCharImpl(s, v);
        return;
    }
    if (v >= 0xA0 && v < 0xE0) {
        if (s->unkF & 1) {
            if (v < 0xC0) {
                v = (v - 0x20) & 0xFF;
            } else {
                v = (v + 0x20) & 0xFF;
            }
        }
        GfxPrint_PrintCharImpl(s, v);
        return;
    }
    if (v >= 0xB) {
        if (v >= 0xE) {
            switch (v) {
            case 0x8A:
                s->unkF = s->unkF & 0xFD;
                s->unkF = s->unkF | 8;
                break;
            case 0x8B:
                s->unkF = s->unkF | 2;
                s->unkF = s->unkF | 8;
                break;
            case 0x8C:
                s->unkF = s->unkF & 0xFE;
                break;
            case 0x8D:
                s->unkF = s->unkF | 1;
                break;
            case 0x8E:
                break;
            }
        } else if (v == 0xD) {
            s->unk8 = s->unkC;
        }
    } else {
        if (v == 9) {
            do {
                GfxPrint_PrintCharImpl(s, 0x20);
            } while ((u8)(s->unk8 - s->unkC) != 0);
        } else if (v == 0xA) {
            s->unkA = s->unkA + 0x20;
            s->unk8 = s->unkC;
        }
    }
}
