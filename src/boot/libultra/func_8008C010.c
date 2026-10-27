// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    u64 interval;
    u64 value;
} Node;

extern Node *D_80098160;
extern u32 __osDisableInt(void);
extern void __osSetCompare(s32 a);
extern void __osRestoreInt(u32 a);

s32 osStopTimer(Node *t) {
    register u32 savedMask;
    Node *timep;

    if (t->next == NULL) {
        return -1;
    }
    savedMask = __osDisableInt();
    timep = t->next;
    if (timep != D_80098160) {
        timep->value += t->value;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    t->next = NULL;
    t->prev = NULL;
    if (D_80098160->next == D_80098160) {
        __osSetCompare(0);
    }
    __osRestoreInt(savedMask);
    return 0;
}
