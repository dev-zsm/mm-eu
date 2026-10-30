#include "types.h"
typedef struct N { s16 id; u8 pad0[0x12C-2]; struct N *next; } N;
typedef struct { u8 pad[0x1CC0]; N *head; } A;
N *func_80000604(A *a) {
    N *p = a->head;
    while (p != 0) {
        if (p->id == 0x174) {
            return p;
        }
        p = p->next;
    }
    return 0;
}
