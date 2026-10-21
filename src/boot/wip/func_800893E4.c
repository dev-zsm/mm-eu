// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
    s32 key;
    struct Node *owner;
} Node;

void func_800893E4(Node *a0, Node *a1) {
    Node *t8 = a0->next;
    Node *t9 = a0;

    if (t8->key < a1->key) goto ins;
    do {
        t9 = t8;
        t8 = t8->next;
    } while (t8->key >= a1->key);
ins:
    a1->next = t9->next;
    t9->next = a1;
    a1->owner = a0;
}
