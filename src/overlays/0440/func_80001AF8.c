// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_80AD7080;
void func_80AD555C();
void func_80001AF8(u8 *a, s32 b) {
    if (*(s32 *)(a + 0x1E54) >= 0x82) {
        func_80AD555C(a, &D_80AD7080);
    }
}
