// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

void func_8008431C(u16 a0);

void func_800843B4(u16 a0) {
    u16 a1 = a0;

    func_8008431C(a1 | 1);
}
