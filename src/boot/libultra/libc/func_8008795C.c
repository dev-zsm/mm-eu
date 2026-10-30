// FLAGS: -O2 -g0 -mips2
#include "arena.h"

s32 func_8008795C(Arena *arena) {
    ArenaNode *node;
    s32 ret = 0;

    // matching: empty check that only shapes the register allocation
    if (!arena) {
    }
    ArenaImpl_Lock(arena);
    node = arena->head;
    if (node != NULL) {
        do {
            if (node->magic != ARENA_NODE_MAGIC) {
                ret = 1;
                break;
            }
            node = node->next;
        } while (node != NULL);
    }
    ArenaImpl_Unlock(arena);
    return ret;
}
