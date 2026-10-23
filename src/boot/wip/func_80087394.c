// FLAGS: -O2 -g0
#include "types.h"
typedef struct Block {
    s16 magic;
    s16 used;
    u32 size;
    struct Block *next;
    struct Block *prev;
} Block;
void *func_80087394(Block **arg0, u32 size) {
    Block *node;
    Block *newNode;
    void *alloc = NULL;
    u32 blockSize;

    size = (size + 0xF) & ~0xF;
    node = *arg0;
    while (node != NULL) {
        if (node->used && node->size >= size) {
            blockSize = ((size + 0xF) & ~0xF) + 0x10;
            if (blockSize < node->size) {
                newNode = (Block *)((u32)node + blockSize);
                newNode->next = node->next;
                newNode->prev = node;
                newNode->size = node->size - blockSize;
                newNode->used = 1;
                newNode->magic = 0x7373;
                node->next = newNode;
                node->size = size;
                if (newNode->next != NULL) {
                    newNode->next->prev = newNode;
                }
            }
            node->used = 0;
            alloc = (u8 *)node + 0x10;
            break;
        }
        node = node->next;
    }
    return alloc;
}
