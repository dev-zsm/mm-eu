// FLAGS: -O2 -g0
#include "systemheap.h"

void SystemHeap_RunBlockFunc1Reverse(void *blocks, u32 count, u32 size, void (*fn)(void *, s32), s32 freeBlocks) {
    u8 *end;
    u8 *p;

    if (blocks != NULL) {
        if (fn != NULL) {
            end = blocks;
            p = blocks;
            p += count * size;
            while (end < p) {
                p -= size ^ 0; // matching: keeps the step in its own register
                fn(p, 2);
            }
        }
        if (freeBlocks != 0) {
            SystemHeap_Free(blocks);
        }
    }
}
