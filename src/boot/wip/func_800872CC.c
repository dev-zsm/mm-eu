// FLAGS: -O2 -g0
#include "types.h"
typedef struct Block { u16 magic; u16 used; s32 size; struct Block *next; struct Block *prev; } Block;
typedef struct Pool { Block *head; u32 start; u8 pad8[0x19]; u8 unk21; } Pool;
void func_800871FC(void *p);
void func_80087224(void *p, u32 a);
Block *func_8008724C(void *p);
void func_800872CC(Pool *arg0, s32 arg1, s32 arg2) {
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
            func_800871FC(arg0);
            tmp = func_8008724C(arg0);
            if (tmp == NULL) {
                arg0->head = blk;
                arg0->start = arg1;
            } else {
                blk->prev = tmp;
                tmp->next = blk;
            }
            func_80087224(arg0, arg1);
        }
    }
}
