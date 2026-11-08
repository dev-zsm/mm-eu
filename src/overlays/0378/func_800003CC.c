// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Pl {
    /* 0x0000 */ u8 pad0[0x1F34];
    /* 0x1F34 */ u16 unk1F34;
} Pl;

void func_800B8C4C();

void func_800003CC(s32 arg0, Pl *play) {
    switch (play->unk1F34) {
        case 0x12:
            func_800B8C4C(arg0, 0x3A8F);
            break;
        case 0x5A:
            func_800B8C4C(arg0, 0x3913);
            break;
        case 0x8E:
            func_800B8C4C(arg0, 0x3A8D);
            break;
    }
}
