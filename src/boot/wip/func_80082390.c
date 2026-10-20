// FLAGS: -O1 -g3 -mips2 -trapuv
#include "types.h"

extern void func_8008482C();
extern u8 D_80098890[];
extern u8 D_800988A0[];
extern u8 D_800988A8[];
extern s32 D_80096D68[];

void func_80082390(u32 arg0) {
    u32 bit;
    s32 i;

    func_8008482C(D_80098890, arg0);
    bit = 0x20000;
    for (i = 0; i != 6; i++) {
        if (arg0 & bit) {
            func_8008482C(D_800988A0, D_80096D68[i]);
            break;
        }
        bit >>= 1;
    }
    func_8008482C(D_800988A8);
}
