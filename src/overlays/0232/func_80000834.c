// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 func_80137C58(u8 *, f32);
void func_800B8C4C();

void func_80000834(u8 *arg0) {
    if (func_80137C58(arg0 + 0x14C, 1.0f) != 0 || func_80137C58(arg0 + 0x14C, 7.0f) != 0) {
        func_800B8C4C(arg0, 0x28EF);
    }
}
