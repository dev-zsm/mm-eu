// FLAGS: -O2 -g0
#include "os_internal.h"

void func_800851C8(void *ptr) {
    *(u16 *)((u8 *)ptr + 0xC) = 0;
    *(u16 *)((u8 *)ptr + 0x12) = 0;
}
