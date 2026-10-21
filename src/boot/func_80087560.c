// FLAGS: -O2 -g0
#include "types.h"
typedef struct Block {
    s16 magic;
    s16 free;
    u32 size;
    struct Block *next;
    struct Block *prev;
} Block;
void func_80087560(s32 a0, Block *a1) {
    Block *cur;
    Block *prev;
    Block *next;
    Block *tmp;
    if (a1 != NULL) {
        cur = (Block *)((u8 *)a1 - 0x10);
        // shortcut: empty test forces the header load before the magic check (matches ROM register order)
        if (cur->free) {
        }
        if (cur->magic == 0x7373 && cur->free == 0) {
            next = cur->next;
            prev = cur->prev;
            cur->free = 1;
            if (next == (Block *)((u8 *)cur + cur->size + 0x10) && next->free != 0) {
                tmp = next->next;
                if (tmp != NULL) {
                    tmp->prev = cur;
                }
                cur->size = cur->size + next->size + 0x10;
                cur->next = tmp;
                next = tmp;
            }
            if (prev != NULL && prev->free != 0 && cur == (Block *)((u8 *)prev + prev->size + 0x10)) {
                if (next != NULL) {
                    next->prev = prev;
                }
                prev->next = next;
                prev->size = prev->size + cur->size + 0x10;
            }
        }
    }
}
