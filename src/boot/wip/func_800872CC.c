// FLAGS: -O2 -g0
#include "types.h"
typedef struct Block { u16 magic; u16 used; s32 size; struct Block *next; struct Block *prev; } Block;
typedef struct Pool { Block *head; u32 start; u8 pad8[0x19]; u8 unk21; } Pool;
void ArenaImpl_Lock(void *p);
void ArenaImpl_Unlock(void *p, u32 a);
Block *ArenaImpl_GetLastBlock(void *p);
void __osMallocAddHeap(Pool *arg0, s32 arg1, s32 arg2) {
    Block *blk;
    Block *tmp;
    s32 n;
    s32 sp20[2];
    if (arg1 != 0) {
        blk = (Block *)((arg1 + 0xF) & ~0xF);
        n = (arg2 - ((s32)blk - arg1)) & ~0xF;
        if (n >= 0x11) {
            blk->next = NULL;
            blk->prev = NULL;
            blk->size = n - 0x10;
            blk->used = 1;
            blk->magic = 0x7373;
            ArenaImpl_Lock(arg0);
            tmp = ArenaImpl_GetLastBlock(arg0);
            if (tmp == NULL) {
                arg0->head = blk;
                arg0->start = arg1;
            } else {
                blk->prev = tmp;
                tmp->next = blk;
            }
            ArenaImpl_Unlock(arg0, arg1);
        }
    }
}
