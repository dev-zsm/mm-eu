// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 PadUtils_CheckReleased(u8 *a0, u16 a1) {
    return ((*(u16 *)(a0 + 0x12) & a1) ^ a1) == 0;
}
