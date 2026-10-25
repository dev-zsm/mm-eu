// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u8 *end;
} AudioHeapBounds;

extern u8 *AudioHeap_Alloc(AudioHeapBounds *heap);

u8 *AudioHeap_AllocZeroed(AudioHeapBounds *heap) {
    u8 *ptr = AudioHeap_Alloc(heap);
    u8 *p;

    if (ptr != NULL) {
        for (p = ptr; p < heap->end; p++) {
            *p = 0;
        }
    }
    return ptr;
}
