// FLAGS: -O2 -g0
#include "types.h"

void func_800851C8(void *a0) {
    *(u16 *)((u8 *)a0 + 0xC) = 0;
    *(u16 *)((u8 *)a0 + 0x12) = 0;
}
