// FLAGS: -O2 -g0 -mips2
#include "types.h"
void bzero(void *a0, s32 a1);
void func_800851A0(void *a0) {
    bzero(a0, 0x18);
}
