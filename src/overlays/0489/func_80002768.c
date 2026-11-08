// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0489.h"

typedef struct E {
    /* 0x0 */ s8 unk0;
    /* 0x1 */ s8 unk1;
    /* 0x2 */ s8 unk2;
    /* 0x3 */ u8 pad3;
    /* 0x4 */ u8 unk4[0xC];
} E;

extern E D_80B35080[];
void func_800FF30C();

s32 func_80002768(s32 arg0) {
    E *e = D_80B35080;
    s32 i = 0;

    do {
        i++;
        if (e->unk1 <= 0) {
            e->unk0 = 0;
            e->unk1 = 0x28;
            func_800FF30C(e->unk4, arg0);
            e->unk2 = 0;
            return 1;
        }
        e++;
    } while (i != 10);
    return 0;
}
