// FLAGS: -O2 -g0 -mips2
#include "types.h"
struct Node {
    u8 pad[8];
    struct Node *next;
};

void *func_8008724C(struct Node **head) {
    struct Node *p = *head;
    struct Node *q;
    if (p != NULL) {
        q = p->next;
        while (q != NULL) {
            p = q;
            q = q->next;
        }
    }
    return p;
}
