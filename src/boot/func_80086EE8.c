// FLAGS: -O2 -g0
#include "types.h"

extern s32 D_8009D0F0;   /* heap handle used by func_8008743C */
void *func_8008743C(s32 *heap, u32 size);
void func_800897D0(void *a, u32 b);

/*
 * Allocates count * elem_size bytes from the heap and zero-fills them (func_800897D0,
 * probably memset). Likely the public calloc(); returns NULL when the allocation fails.
 */
void *func_80086EE8(u32 count, u32 elem_size) {
    void *ptr;
    u32 size = count * elem_size;
    ptr = func_8008743C(&D_8009D0F0, size);
    if (ptr != 0) {
        func_800897D0(ptr, size);
    }
    return ptr;
}
