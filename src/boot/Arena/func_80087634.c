// FLAGS: -O2 -g0
#include "boot/arena.h"

void Arena_Free(Arena *arena, void *ptr) {
    ArenaImpl_Lock(arena);
    func_80087560(arena, ptr);
    ArenaImpl_Unlock(arena);
}
