// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u32 head;
    u32 tail;
    u32 initValue;
    s32 minSpace;
} StackEntry;

s32 StackCheck_GetState(StackEntry *entry) {
    u32 *last;
    u32 free;
    s32 status;

    for (last = (u32 *)entry->head; last < (u32 *)entry->tail; last++) {
        if (entry->initValue != *last) {
            break;
        }
    }
    free = (u32)last - entry->head;
    if (free == 0) {
        status = 2;
    } else if (free < entry->minSpace && entry->minSpace != -1) {
        status = 1;
    } else {
        status = 0;
    }
    return status;
}
