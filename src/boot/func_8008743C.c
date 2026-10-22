// FLAGS: -O2 -g0
#include "types.h"
void ArenaImpl_Lock(s32 a0, u32 a1);
void ArenaImpl_Unlock(s32 a0);
void *func_80087394(s32 a0, u32 a1);

/*
 * Allocates size bytes from heap under the heap lock (ArenaImpl_Lock / ArenaImpl_Unlock);
 * the actual allocation is func_80087394. Likely the public malloc().
 */
void *func_8008743C(s32 heap, u32 size) {
    void *ptr;
    ArenaImpl_Lock(heap, size);
    ptr = func_80087394(heap, size);
    ArenaImpl_Unlock(heap);
    return ptr;
}
