// FLAGS: -O2 -g3
#include "types.h"
typedef struct Block {
    s16 magic;
    s16 free;
    u32 size;
    struct Block *next;
    struct Block *prev;
} Block;
void func_800871FC(s32 a0, u32 a1);
void func_80087224(s32 a0);
Block *func_8008724C(s32 a0);
void *func_8008747C(s32 a0, u32 a1) {
    void *ret;
    Block *b;
    Block *nb;
    u32 need;
    a1 = (a1 + 0xF) & ~0xF;
    ret = NULL;
    func_800871FC(a0, a1);
    b = func_8008724C(a0);
    if (b != NULL) {
        while (b != NULL) {
            if (b->free != 0 && b->size >= a1) {
                need = ((a1 + 0xF) & ~0xF) + 0x10;
                if (need < b->size) {
                    nb = (Block *)((u8 *)b + b->size - a1);
                    nb->prev = b;
                    nb->size = a1;
                    nb->magic = 0x7373;
                    nb->next = b->next;
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
    }
    func_80087224(a0);
    return ret;
}
