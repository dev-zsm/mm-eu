// FLAGS: -O2 -g0 -mips2
#include "libc.h"

void GetFreeArena(u32 *maxFree, u32 *bytesFree, u32 *bytesAllocated) {
    func_800878AC(&D_8009D0F0, maxFree, bytesFree, bytesAllocated);
}
