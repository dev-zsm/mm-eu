// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct A { s16 id; u8 pad[0x12A]; struct A *next; } A;
typedef struct { u8 pad[0x1D08]; A *head; } S;

A *func_80000438(S *s) {
    A *a = s->head;
    while (a != 0) {
        if (a->id == 0x8E) {
            return a;
        }
        a = a->next;
    }
    return 0;
}
