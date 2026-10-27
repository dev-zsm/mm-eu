// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Entrance_Create(s32 arg0, s32 arg1, s32 arg2) {
    return ((arg0 << 9) | (arg1 * 0x10) | arg2) & 0xFFFF;
}
