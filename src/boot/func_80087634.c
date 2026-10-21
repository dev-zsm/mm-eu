// FLAGS: -O2 -g0
#include "types.h"
void func_800871FC(s32 a0, void *a1);
void func_80087224(s32 a0);
void func_80087560(s32 a0, void *a1);

/*
 * Frees ptr from heap: takes the heap lock (func_800871FC), frees and merges the
 * block (func_80087560), then releases the lock (func_80087224). Likely the public free().
 */
void func_80087634(s32 heap, void *ptr) {
    func_800871FC(heap, ptr);
    func_80087560(heap, ptr);
    func_80087224(heap);
}
