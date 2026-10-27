// FLAGS: -O1 -g0 -mips2
#include "types.h"
typedef struct Node { struct Node *next; } Node;
void func_800895D0(Node **queue, Node *t) {
    register Node *pred;
    register Node *succ;
    pred = (Node *)queue;
    succ = pred->next;
    while (succ != 0) {
        if (succ == t) {
            pred->next = t->next;
            break;
        }
        pred = succ;
        succ = pred->next;
    }
}
