// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void *AudioHeap_Alloc();
extern void *AudioHeap_WritebackDCache();
void *AudioHeap_AllocDmaMemory(s32 a0, s32 a1) {
    void *r = AudioHeap_Alloc(a0);
    if (r != NULL) {
        r = AudioHeap_WritebackDCache(r, a1);
    }
    return r;
}
