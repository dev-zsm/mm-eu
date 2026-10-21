// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_80085208(u8 *a0, u16 a1) {
    return ((*(u16 *)(a0 + 0xC) & a1) ^ a1) == 0;
}
