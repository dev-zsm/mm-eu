// FLAGS: -O2 -g0
#include "arena.h"

void __osMallocAddHeap(Arena *arena, void *start, size_t size) {
    ArenaNode *firstNode;
    ArenaNode *lastNode;
    u32 diff;
    s32 end;

    if (start == NULL) {
        return;
    }
    firstNode = (ArenaNode *)(((u32)start + 0xF) & ~0xF);
    diff = (u32)firstNode - (u32)start;
    end = size - diff;
    end &= ~0xF;
    if (end > 0x10) {
        firstNode->next = NULL;
        firstNode->prev = NULL;
        firstNode->size = end - 0x10;
        firstNode->isFree = 1;
        firstNode->magic = ARENA_NODE_MAGIC;
        ArenaImpl_Lock(arena);
        lastNode = ArenaImpl_GetLastBlock(arena);
        if (lastNode == NULL) {
            arena->head = firstNode;
            arena->start = start;
        } else {
            firstNode->prev = lastNode;
            lastNode->next = firstNode;
        }
        ArenaImpl_Unlock(arena);
    }
}
