// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u8 padA[2];
    u32 unkC;
} Ctx;

extern Ctx *D_80098080[];
typedef volatile u32 vu32;

s32 __osEPiRawReadIo(Ctx *src, s32 arg1, u32 *dst) {
    Ctx *ent;
    u32 st;
    vu32 *reg;
    reg = (vu32 *)0xA4600010;
    st = *reg;
    while (st & 3) {
        st = *reg;
    }
    ent = D_80098080[src->unk9];
    if (src->unk4 != ent->unk4) {
        if (src->unk9 == 0) {
            if (src->unk5 != ent->unk5) {
                *(u32 *)0xA4600014 = src->unk5;
            }
            if (src->unk6 != ent->unk6) {
                *(u32 *)0xA460001C = src->unk6;
            }
            if (src->unk7 != ent->unk7) {
                *(u32 *)0xA4600020 = src->unk7;
            }
            if (src->unk8 != ent->unk8) {
                *(u32 *)0xA4600018 = src->unk8;
            }
        } else {
            if (src->unk5 != ent->unk5) {
                *(u32 *)0xA4600024 = src->unk5;
            }
            if (src->unk6 != ent->unk6) {
                *(u32 *)0xA460002C = src->unk6;
            }
            if (src->unk7 != ent->unk7) {
                *(u32 *)0xA4600030 = src->unk7;
            }
            if (src->unk8 != ent->unk8) {
                *(u32 *)0xA4600028 = src->unk8;
            }
        }
        ent->unk4 = src->unk4;
        ent->unk5 = src->unk5;
        ent->unk6 = src->unk6;
        ent->unk7 = src->unk7;
        ent->unk8 = src->unk8;
    }
    *dst = *(u32 *)(src->unkC | arg1 | 0xA0000000);
    return 0;
}
