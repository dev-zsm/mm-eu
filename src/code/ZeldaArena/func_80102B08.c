#include "types.h"

extern u8 D_801EC980[];

void *func_8008743C(u8 *arena, u32 size);
void func_800897D0(void *ptr, u32 size);

void *ZeldaArena_Calloc(u32 num, u32 size) {
    void *ptr;
    u32 total = num * size;

    ptr = func_8008743C(D_801EC980, total);
    if (ptr != NULL) {
        func_800897D0(ptr, total);
    }
    return ptr;
}
