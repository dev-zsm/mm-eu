#include "types.h"
extern u8 D_80B5F9B4[];
extern void func_80B5DB5C();
void func_80001DF0(s32 a0, s32 a1, s32 a2, u16 a3) {
    if (a3 == 0x33BF) {
        func_80B5DB5C(a1, D_80B5F9B4);
    }
}
