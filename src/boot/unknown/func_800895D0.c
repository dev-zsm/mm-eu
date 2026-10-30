// FLAGS: -O1 -g0 -mips2
#include "os_internal.h"

void func_800895D0(OSThread **queue, OSThread *t) {
    register OSThread *pred;
    register OSThread *succ;

    pred = (OSThread *)queue;
    succ = pred->next;
    while (succ != NULL) {
        if (succ == t) {
            pred->next = t->next;
            break;
        }
        pred = succ;
        succ = pred->next;
    }
}
