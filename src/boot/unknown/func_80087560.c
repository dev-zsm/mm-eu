// FLAGS: -O2 -g0
#include "types.h"

/* Header placed immediately before every heap payload (0x10 bytes). */
typedef struct Block {
    s16 magic;
    s16 is_free;
    u32 size;               /* payload size, excluding the header */
    struct Block *next;     /* physically following block */
    struct Block *prev;     /* physically preceding block */
} Block;

#define BLOCK_HEADER_SIZE 0x10
#define BLOCK_MAGIC_USED  0x7373

/*
 * Frees the block whose payload starts at ptr and merges it with a free neighbour
 * on either side. Heap handle heap is unused here. Internal helper, SDK name unknown.
 */
void func_80087560(s32 heap, Block *ptr) {
    Block *block;
    Block *prev;
    Block *next;
    Block *after_next;

    if (ptr != NULL) {
        block = (Block *)((u8 *)ptr - BLOCK_HEADER_SIZE);
        // shortcut: empty test forces the header load before the magic check (matches ROM register order)
        if (block->is_free) {
        }
        if (block->magic == BLOCK_MAGIC_USED && block->is_free == 0) {
            next = block->next;
            prev = block->prev;
            block->is_free = 1;
            if (next == (Block *)((u8 *)block + block->size + BLOCK_HEADER_SIZE) && next->is_free != 0) {
                after_next = next->next;
                if (after_next != NULL) {
                    after_next->prev = block;
                }
                block->size = block->size + next->size + BLOCK_HEADER_SIZE;
                block->next = after_next;
                next = after_next;
            }
            if (prev != NULL && prev->is_free != 0 && block == (Block *)((u8 *)prev + prev->size + BLOCK_HEADER_SIZE)) {
                if (next != NULL) {
                    next->prev = prev;
                }
                prev->next = next;
                prev->size = prev->size + block->size + BLOCK_HEADER_SIZE;
            }
        }
    }
}
