// FLAGS: -O2 -g0 -mips2
#include "stackcheck.h"

void StackCheck_Cleanup(StackEntry *entry) {
    s32 bad = 0;

    if (entry->prev == NULL) {
        if (D_80096DE0 == entry) {
            D_80096DE0 = entry->next;
        } else {
            bad = 1;
        }
    } else {
        entry->prev->next = entry->next;
    }
    if (entry->next == NULL) {
        if (D_80096DE4 == entry) {
            D_80096DE4 = entry->prev;
        } else {
            bad = 1;
        }
    }
    if (bad) {
        /* matching: the empty branch keeps the register allocation */
    }
}
