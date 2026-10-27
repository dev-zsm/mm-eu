// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801FAE80;
extern void *AudioHeap_AllocZeroed(void *heap, s32 size);
void *AudioHeap_AllocZeroedAttemptExternal(void *heap, s32 size) {
    void *ret = (void *) 0;
    if (D_801FAE80 != 0) {
        ret = AudioHeap_AllocZeroed(&D_801FAE80, size);
    }
    if (ret == ((void *) 0)) {
        ret = AudioHeap_AllocZeroed(heap, size);
        D_801FAE80 += 0;
    }
    return ret;
}
