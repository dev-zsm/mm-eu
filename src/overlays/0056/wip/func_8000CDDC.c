// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern void func_80839E6C();

void func_8000CDDC(u8 *a0, s32 a1, s16 a2) {
    *(s16 *)(a0 + 0xAD4) = a2;
    *(s16 *)(a0 + 0xBE) = *(s16 *)(a0 + 0xAD4);
    func_80839E6C(a0);
}
