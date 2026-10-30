// FLAGS: -O2 -g0
#include "arena.h"

void *func_8008743C(Arena *arena, size_t size) {
    void *ptr;

    ArenaImpl_Lock(arena);
    ptr = func_80087394(arena, size);
    ArenaImpl_Unlock(arena);
    return ptr;
}
