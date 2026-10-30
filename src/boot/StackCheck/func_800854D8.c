// FLAGS: -O2 -g0 -mips2
#include "stackcheck.h"

s32 StackCheck_GetState(StackEntry *entry) {
    u32 *last;
    u32 free;
    s32 status;

    for (last = entry->head; last < entry->tail; last++) {
        if (entry->initValue != *last) {
            break;
        }
    }
    free = (u32)last - (u32)entry->head;
    if (free == 0) {
        status = 2;
    } else if (free < entry->minSpace && entry->minSpace != -1) {
        status = 1;
    } else {
        status = 0;
    }
    return status;
}
