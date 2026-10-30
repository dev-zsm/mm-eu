// FLAGS: -O2 -g0 -mips2
#include "arena.h"

void func_800878AC(Arena *arena, u32 *maxFree, u32 *bytesFree, u32 *bytesAllocated) {
    ArenaNode *node;

    ArenaImpl_Lock(arena);
    *maxFree = 0;
    *bytesFree = 0;
    *bytesAllocated = 0;
    for (node = arena->head; node != NULL; node = node->next) {
        if (node->isFree != 0) {
            *bytesFree += node->size;
            if (*maxFree < node->size) {
                *maxFree = node->size;
            }
        } else {
            *bytesAllocated += node->size;
        }
    }

    ArenaImpl_Unlock(arena);
}
