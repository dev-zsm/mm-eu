// FLAGS: -O2 -g3 -mips2
#include "types.h"

void func_8008F3E0(void *a, void *b, u32 c);
s32 func_80080C54(void *a, s32 b, s32 c, s32 d, s32 e, void *f, s32 g);
void func_80088070(void *a, u32 b, u32 c);

s32 func_80080CE0(s32 a0, s32 a1, s32 a2) {
    u8 sp48[0x20];
    u8 sp30[0x18];
    u8 sp2C[0x4];
    s32 temp_v0;

    func_8008F3E0(sp30, sp2C, 1);
    temp_v0 = func_80080C54(sp48, a0, a1, a2, 0, sp30, 0);
    if (temp_v0 == -1) {
        return temp_v0;
    }
    func_80088070(sp30, 0, 1);
    return 0;
}
