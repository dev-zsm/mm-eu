// FLAGS: -O2 -g0
#include "arena.h"

/* Allocates from the end of a free block, scanning from the last block backwards. */
void *func_8008747C(Arena *arena, size_t size) {
    ArenaNode *node;
    ArenaNode *newNode;
    u32 need;
    void *ret;

    size = (size + 0xF) & ~0xF;
    ret = NULL;
    ArenaImpl_Lock(arena);
    node = ArenaImpl_GetLastBlock(arena);
    while (node != NULL) {
        if (node->isFree != 0 && node->size >= size) {
            need = ((size + 0xF) & ~0xF) + 0x10;
            if (need < node->size) {
                newNode = (ArenaNode *)((u8 *)node + node->size - size);
                newNode->next = node->next;
                newNode->prev = node;
                newNode->size = size;
                newNode->magic = ARENA_NODE_MAGIC;
                node->next = newNode;
                node->size = node->size - need;
                if (newNode->next != NULL) {
                    newNode->next->prev = newNode;
                }
                node = newNode;
            }
            node->isFree = 0;
            ret = (u8 *)node + 0x10;
            break;
        }
        node = node->prev;
    }
    ArenaImpl_Unlock(arena);
    return ret;
}
