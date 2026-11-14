// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x24];
    u8 unk24[0xC];
    s16 unk32;
} Sub;

typedef struct {
    u8 pad0[0x24];
    u8 unk24[0x284];
    Sub *unk2A8;
} Act;

void func_800FF30C();
s16 func_800FF860();

s32 func_800012B0(Act *this, void *play) {
    u8 sp2C[12];
    u8 sp20[12];
    u8 *p = (u8 *)this->unk2A8;

    if (p != NULL && *(s32 *)(p + 0x138) != 0) {
        func_800FF30C(sp2C, p + 0x24);
        func_800FF30C(sp20, (u8 *)this + 0x24);
        *(s16 *)((u8 *)this + 0x32) = func_800FF860(sp20, sp2C);
    }
    return 1;
}
