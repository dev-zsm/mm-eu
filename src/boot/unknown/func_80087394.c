// FLAGS: -O2 -g0
#include "arena.h"

void *func_80087394(Arena *arena, size_t size) {
    ArenaNode *node;
    ArenaNode *newNode;
    void *alloc = NULL;
    int new_var; // matching: the second rounding stays in a separate local
    u32 blockSize;

    size = (size + 0xF) & ~0xF;
    new_var = ((size + 0xF) & ~0xF) + 0x10;
    node = arena->head;
    while (node != NULL) {
        if (node->isFree && node->size >= size) {
            blockSize = new_var;
            if (blockSize < node->size) {
                newNode = (ArenaNode *)((u32)node + blockSize);
                newNode->next = node->next;
                newNode->prev = node;
                newNode->size = node->size - blockSize;
                newNode->isFree = 1;
                newNode->magic = ARENA_NODE_MAGIC;
                node->next = newNode;
                node->size = size;
                if (newNode->next != NULL) {
                    newNode->next->prev = newNode;
                }
            }
            node->isFree = 0;
            alloc = (u8 *)node + 0x10;
            break;
        }
        node = node->next;
    }

    return alloc;
}
