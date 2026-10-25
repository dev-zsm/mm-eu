// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801FAE80;
extern void *AudioHeap_Alloc(void *pool, s32 size);
void *AudioHeap_AllocAttemptExternal(void *pool, s32 size) {
    void *ret = (void *) 0;
    if (D_801FAE80 != 0) {
        ret = AudioHeap_Alloc(&D_801FAE80, size);
    }
    if (ret == ((void *) 0)) {
        ret = AudioHeap_Alloc(pool, size);
        if (D_801FAE80) {
        }
    }
    return ret;
}
