// FLAGS: -O1 -g0 -mips2
#include "types.h"

u32 osGetMemSize(void) {
    u32 *ptr;
    u32 size;
    u32 data0;
    u32 data1;

    size = 0x400000;
    do {
        ptr = (u32 *)(0xA0000000 + size);
        data0 = *(u32 *)(0xA0000000 + size);
        data1 = *(u32 *)(0xA0000000 + size + 0xFFFFC);
        *(u32 *)(0xA0000000 + size) ^= 0xFFFFFFFF;
        *(u32 *)((u32)ptr + 0xFFFFC) ^= 0xFFFFFFFF;
        if (*ptr != (data0 ^ 0xFFFFFFFF) || *(u32 *)((u32)ptr + 0xFFFFC) != (data1 ^ 0xFFFFFFFF)) {
            return size;
        }
        *ptr = data0;
        *(u32 *)((u32)ptr + 0xFFFFC) = data1;
        size += 0x100000;
    } while (size < 0x800000);
    return size;
}
