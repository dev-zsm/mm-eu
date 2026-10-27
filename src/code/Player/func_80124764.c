#include "types.h"

s32 func_80124764(u8 *arg0) {
    return (*(u32 *)(arg0 + 0xA6C) & 0x8000000) && (*(s8 *)(arg0 + 0x145) < 5);
}
