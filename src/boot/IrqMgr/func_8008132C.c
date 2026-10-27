// FLAGS: -O2 -g3
#include "types.h"

s32 osSetIntMask(s32);

typedef struct Node {
    struct Node *next;
    s32 data;
} Node;

typedef struct Owner {
    u8 pad0[0x248];
    Node *list;
} Owner;

void IrqMgr_RemoveClient(Owner *arg0, Node *arg1) {
    Node *cur;
    Node *prev;
    s32 irq;

    prev = NULL;
    cur = arg0->list;
    irq = osSetIntMask(1);
    while (cur != NULL) {
        if (cur == arg1) {
            if (prev != NULL) {
                prev->next = arg1->next;
            } else {
                arg0->list = arg1->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    osSetIntMask(irq);
}
