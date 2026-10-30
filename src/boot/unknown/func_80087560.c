// FLAGS: -O2 -g0
#include "arena.h"

/* Frees the block whose payload starts at ptr and merges it with a free neighbour on either side. */
void func_80087560(Arena *arena, void *ptr) {
    ArenaNode *node;
    ArenaNode *prev;
    ArenaNode *next;
    ArenaNode *afterNext;

    if (ptr != NULL) {
        node = (ArenaNode *)((u8 *)ptr - ARENA_NODE_SIZE);
        // matching: the empty test forces the header load before the magic check
        if (node->isFree) {
        }
        if (node->magic == ARENA_NODE_MAGIC && node->isFree == 0) {
            next = node->next;
            prev = node->prev;
            node->isFree = 1;
            if (next == (ArenaNode *)((u8 *)node + node->size + ARENA_NODE_SIZE) && next->isFree != 0) {
                afterNext = next->next;
                if (afterNext != NULL) {
                    afterNext->prev = node;
                }
                node->size = node->size + next->size + ARENA_NODE_SIZE;
                node->next = afterNext;
                next = afterNext;
            }
            if (prev != NULL && prev->isFree != 0 && node == (ArenaNode *)((u8 *)prev + prev->size + ARENA_NODE_SIZE)) {
                if (next != NULL) {
                    next->prev = prev;
                }
                prev->next = next;
                prev->size = prev->size + node->size + ARENA_NODE_SIZE;
            }
        }
    }
}
