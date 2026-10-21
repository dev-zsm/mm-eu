// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct PiTiming {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 padA[2];
    u32 unkC;
} PiTiming;

extern PiTiming *D_80098080[];

s32 func_80094190(PiTiming *a0, PiTiming *a1, u32 a2) {
    u32 off;
    u8 idx;
    u32 st;
    PiTiming *ent;

    st = *(volatile u32 *)0xA4600010;
    off = (u32)a1;
    if (st & 3) {
        do {
            st = *(volatile u32 *)0xA4600010;
        } while (st & 3);
    }
    idx = a0->unk9;
    ent = D_80098080[idx];
    if (a0->unk4 != ent->unk4) {
        a1 = ent;
        if (idx == 0) {
            if (a1->unk5 != a0->unk5) {
                *(u32 *)0xA4600014 = a0->unk5;
            }
            if (a1->unk6 != a0->unk6) {
                *(u32 *)0xA460001C = a0->unk6;
            }
            if (a1->unk7 != a0->unk7) {
                *(u32 *)0xA4600020 = a0->unk7;
            }
            if (a1->unk8 != a0->unk8) {
                *(u32 *)0xA4600018 = a0->unk8;
            }
        } else {
            if (a1->unk5 != a0->unk5) {
                *(u32 *)0xA4600024 = a0->unk5;
            }
            if (a1->unk6 != a0->unk6) {
                *(u32 *)0xA460002C = a0->unk6;
            }
            if (a1->unk7 != a0->unk7) {
                *(u32 *)0xA4600030 = a0->unk7;
            }
            if (a1->unk8 != a0->unk8) {
                *(u32 *)0xA4600028 = a0->unk8;
            }
        }
        a1->unk4 = a0->unk4;
        a1->unk5 = a0->unk5;
        a1->unk6 = a0->unk6;
        a1->unk7 = a0->unk7;
        a1->unk8 = a0->unk8;
    }
    *(u32 *)((a0->unkC | off) | 0xA0000000) = a2;
    return 0;
}
