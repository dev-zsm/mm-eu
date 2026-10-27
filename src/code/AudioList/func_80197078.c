#include "types.h"

typedef struct {
    u8 pad0[0x34];
    u8 priority;
} Note7078;

typedef struct ListItem7078 {
    struct ListItem7078 *prev;
    struct ListItem7078 *next;
    Note7078 *value;
} ListItem7078;

Note7078 *AudioList_FindNodeWithPrioLessThan(ListItem7078 *list, s32 limit) {
    ListItem7078 *cur = list->next;
    ListItem7078 *best;

    if (cur == list) {
        return NULL;
    }
    for (best = cur; cur != list; cur = cur->next) {
        if (best->value->priority >= cur->value->priority) {
            best = cur;
        }
    }
    if (best == NULL) {
        return NULL;
    }
    if (best->value->priority >= limit) {
        return NULL;
    }
    return best->value;
}
