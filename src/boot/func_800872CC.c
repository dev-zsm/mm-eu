// FLAGS: -O2 -g0
#include "types.h"

typedef struct Block {
    u16 magic;
    u16 isFree;
    s32 size;
    struct Block *next;
    struct Block *prev;
} Block;

typedef struct Pool {
    Block *head;
    void *start;
} Pool;

extern void ArenaImpl_Lock(Pool *p);
extern void ArenaImpl_Unlock(Pool *p);
extern Block *ArenaImpl_GetLastBlock(Pool *p);

void __osMallocAddHeap(Pool *arena, void *start, s32 size) {
    Block *firstNode;
    Block *lastNode;
    u32 diff;
    s32 end;

    if (start == NULL) {
        return;
    }
    firstNode = (Block *)(((u32)start + 0xF) & ~0xF);
    diff = (u32)firstNode - (u32)start;
    end = size - diff;
    end &= ~0xF;
    if (end > 0x10) {
        firstNode->next = NULL;
        firstNode->prev = NULL;
        firstNode->size = end - 0x10;
        firstNode->isFree = 1;
        firstNode->magic = 0x7373;
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
