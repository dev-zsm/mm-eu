// FLAGS: -O2 -g0
#include "arena.h"

void __osMallocInit(Arena *arena, void *start, size_t size) {
    bzero(arena, sizeof(Arena));
    ArenaImpl_LockInit(arena);
    __osMallocAddHeap(arena, start, size);
    arena->isInit = 1;
}
