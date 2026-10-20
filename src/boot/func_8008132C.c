// FLAGS: -O2 -g3
#include "types.h"

s32 func_800881B0(s32);

typedef struct Node {
    struct Node *next;
    s32 data;
} Node;

typedef struct Owner {
    u8 pad0[0x248];
    Node *list;
} Owner;

void func_8008132C(Owner *arg0, Node *arg1) {
    Node *cur;
    Node *prev;
    s32 irq;

    prev = NULL;
    cur = arg0->list;
    irq = func_800881B0(1);
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
    func_800881B0(irq);
}
