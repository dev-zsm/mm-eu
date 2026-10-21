// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
} Node;

void func_800895D0(Node *a0, Node *a1) {
    Node *a2 = a0;
    Node *a3 = a2->next;

    if (a3 != NULL) {
        do {
            if (a3 == a1) {
                a2->next = a1->next;
                break;
            }
            a2 = a3;
            a3 = a2->next;
        } while (a3 != NULL);
    }
}
