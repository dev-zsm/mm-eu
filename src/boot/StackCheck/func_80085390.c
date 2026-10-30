// FLAGS: -O2 -g0 -mips2
#include "stackcheck.h"

void StackCheck_Init(StackEntry *entry, void *stackBottom, void *stackTop, u32 initValue, s32 minSpace, const char *name) {
    StackEntry *iter;
    u32 *p;

    if (entry == NULL) {
        D_80096DE0 = NULL;
        return;
    }
    entry->head = stackBottom;
    entry->tail = stackTop;
    entry->initValue = initValue;
    entry->minSpace = minSpace;
    entry->name = name;
    for (iter = D_80096DE0; iter != NULL; iter = iter->next) {
        if (iter == entry) {
            return;
        }
    }
    entry->prev = D_80096DE4;
    entry->next = NULL;
    if (D_80096DE4 != NULL) {
        D_80096DE4->next = entry;
    }
    D_80096DE4 = entry;
    if (D_80096DE0 == NULL) {
        D_80096DE0 = entry;
    }
    if (entry->minSpace != -1) {
        for (p = entry->head; p < entry->tail; p++) {
            *p = entry->initValue;
        }
    }
}
