// FLAGS: -O2 -g0
#include "types.h"
void func_800871FC(s32 a0, u32 a1);
void func_80087224(s32 a0);
void *func_80087394(s32 a0, u32 a1);

/*
 * Allocates size bytes from heap under the heap lock (func_800871FC / func_80087224);
 * the actual allocation is func_80087394. Likely the public malloc().
 */
void *func_8008743C(s32 heap, u32 size) {
    void *ptr;
    func_800871FC(heap, size);
    ptr = func_80087394(heap, size);
    func_80087224(heap);
    return ptr;
}
