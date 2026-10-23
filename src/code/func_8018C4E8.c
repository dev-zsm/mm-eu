// FLAGS: -O2 -g0
#include "types.h"
extern void *AudioHeap_AllocZeroed(void *a0, s32 a1);
extern void *AudioHeap_WritebackDCache(void *a0, s32 a1);
void *AudioHeap_AllocDmaMemoryZeroed(void *a0, s32 a1) {
    void *p = AudioHeap_AllocZeroed(a0, a1);
    if (p != 0) {
        p = AudioHeap_WritebackDCache(p, a1);
    }
    return p;
}
