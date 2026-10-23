// FLAGS: -O2 -g0
#include "types.h"
typedef struct Block {
    s16 magic;
    s16 free;
    u32 size;
    struct Block *next;
    struct Block *prev;
} Block;
void ArenaImpl_Lock(s32 a0, u32 a1);
void ArenaImpl_Unlock(s32 a0);
Block *ArenaImpl_GetLastBlock(s32 a0);
void *func_8008747C(s32 a0, u32 a1) {
    Block *b;
    Block *nb;
    u32 need;
    void *ret;

    a1 = (a1 + 0xF) & ~0xF;
    ret = NULL;
    ArenaImpl_Lock(a0, a1);
    b = ArenaImpl_GetLastBlock(a0);
    while (b != NULL) {
        if (b->free != 0 && b->size >= a1) {
            need = ((a1 + 0xF) & ~0xF) + 0x10;
            if (need < b->size) {
                nb = (Block *)((u8 *)b + b->size - a1);
                nb->next = b->next;
                nb->prev = b;
                nb->size = a1;
                nb->magic = 0x7373;
                b->next = nb;
                b->size = b->size - need;
                if (nb->next != NULL) {
                    nb->next->prev = nb;
                }
                b = nb;
            }
            b->free = 0;
            ret = (u8 *)b + 0x10;
            break;
        }
        b = b->prev;
    }
    ArenaImpl_Unlock(a0);
    return ret;
}
