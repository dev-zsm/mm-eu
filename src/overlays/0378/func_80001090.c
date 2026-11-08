// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1F34];
    /* 0x1F34 */ u16 unk1F34;
} Pl;

void func_800B8C4C();

void func_80001090(s32 arg0, Pl *arg1) {
    switch (arg1->unk1F34) {
        case 0x137:
            func_800B8C4C(arg0, 0x3AA0);
            break;
        case 0x16D:
            func_800B8C4C(arg0, 0x3915);
            break;
        case 0x174:
            func_800B8C4C(arg0, 0x3913);
            func_800B8C4C(arg0, 0x390C);
            break;
    }
}
