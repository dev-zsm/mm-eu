// FLAGS: -O2 -g0 -mips1
#include "types.h"

u16 Sram_CalcChecksum(u8 *data, u32 size) {
    u16 sum = 0;

    while (size--) {
        sum += *data++;
    }
    return sum;
}
