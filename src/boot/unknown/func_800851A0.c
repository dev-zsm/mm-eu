// FLAGS: -O2 -g0 -mips2
// The trailing empty function at 0x800851C0 is part of the 0x28-byte ROM chunk.
#include "types.h"
void bzero(void *a0, s32 a1);
void func_800851A0(void *a0) {
    bzero(a0, 0x18);
}
void func_800851C0(void) {
}
