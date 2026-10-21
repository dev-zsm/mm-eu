// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Thread {
    struct Thread *next;
} Thread;

// best attempt: 2 instr differ (ROM loads the next pointer into t9, ours picks t6)
Thread *func_8008942C(Thread **queue) {
    register Thread *t = *queue;

    *queue = t->next;
    return t;
}
