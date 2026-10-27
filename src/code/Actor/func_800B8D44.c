#include "types.h"

void func_800B8D44(u8 *arg0, u16 arg1) {
    *(u16 *)(arg0 + 0x50) = arg1;
    // The 16-bit mask (instead of 0xE0) is what the ROM encodes.
    arg0[0x39] = (u16)arg0[0x39] & 0xFFE0;
    arg0[0x39] |= 4;
}
