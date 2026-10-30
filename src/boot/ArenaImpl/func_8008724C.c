// FLAGS: -O2 -g0 -mips2
#include "arena.h"

ArenaNode *ArenaImpl_GetLastBlock(Arena *arena) {
    ArenaNode *p = arena->head;
    ArenaNode *q;

    if (p != NULL) {
        q = p->next;
        while (q != NULL) {
            p = q;
            q = q->next;
        }
    }
    return p;
}
