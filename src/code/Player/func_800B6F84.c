#include "types.h"

s32 func_800B6F84(u8 *arg0) {
    return ((*(u32 *)(arg0 + 0xA6C) & 0x20000080) != 0) || (arg0[0x394] != 0);
}
