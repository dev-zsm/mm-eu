// FLAGS: -O2 -g0
#include "systemheap.h"

void SystemHeap_RunBlockFunc1(void *blocks, u32 count, u32 size, void (*fn)(void *, s32)) {
    u8 *end;
    u8 *p = blocks;

    end = blocks;
    end += count * size;
    if (p < end) {
        do {
            fn(p, 2);
            p += size ^ 0; // matching: keeps the step in its own register
        } while (p < end);
    }
}
