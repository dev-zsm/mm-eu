// FLAGS: -O2 -g0 -mips2
#include "types.h"

s8 PadUtils_GetCurX(u8 *a0) {
    return *(s8 *)(a0 + 0x2);
}
