// FLAGS: -O2 -g0
#include "types.h"
typedef struct Block {
    u16 magic;
    s16 used;
    s32 size;
    struct Block *next;
    struct Block *prev;
} Block;
typedef struct Pool {
    Block *head;
    u32 start;
} Pool;
void *func_80087394(void **arg0, u32 arg1) {
    u32 v0;
    Block *nb;
    Block *b;
    b = *arg0;
    arg1 = (arg1 + 0xF) & ~0xF;
    while (b != NULL) {
        if (b->used != 0) {
            if ((u32)b->size >= arg1) {
                v0 = ((arg1 + 0xF) & ~0xF) + 0x10;
                if (v0 < (u32)b->size) {
                    nb = (Block *)((u8 *)b + v0);
                    nb->prev = b;
                    nb->next = b->next;
                    nb->used = 1;
                    nb->size = b->size - v0;
                    nb->magic = 0x7373;
                    b->next = nb;
                    b->size = arg1;
                    if (nb->next != NULL) {
                        nb->next->prev = nb;
                    }
                }
                b->used = 0;
                return (u8 *)b + 0x10;
            }
        }
        b = b->next;
    }
    return NULL;
}
