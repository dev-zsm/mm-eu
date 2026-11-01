// FLAGS: -O2 -g0 -mips2
#include "boot/stackcheck.h"
#include "generated/boot_funcs.h"

s32 StackCheck_CheckAll(void) {
    StackEntry *iter;
    s32 found;

    iter = D_80096DE0;
    found = 0;
    if (iter != NULL) {
        do {
            if (StackCheck_GetState(iter) != 0) {
                found = 1;
            }
            iter = iter->next;
        } while (iter != NULL);
    }
    return found;
}
