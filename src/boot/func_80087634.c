// FLAGS: -O2 -g0
#include "types.h"
void ArenaImpl_Lock(s32 a0, void *a1);
void ArenaImpl_Unlock(s32 a0);
void func_80087560(s32 a0, void *a1);

/*
 * Frees ptr from heap: takes the heap lock (ArenaImpl_Lock), frees and merges the
 * block (func_80087560), then releases the lock (ArenaImpl_Unlock). Likely the public Arena_Free().
 */
void Arena_Free(s32 heap, void *ptr) {
    ArenaImpl_Lock(heap, ptr);
    func_80087560(heap, ptr);
    ArenaImpl_Unlock(heap);
}
