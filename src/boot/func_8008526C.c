// FLAGS: -O2 -g0 -mips2
#include "types.h"

s8 PadUtils_GetRelXImpl(u8 *a0) {
    return *(s8 *)(a0 + 0x14);
}
