#include "types.h"
typedef struct { u16 capacity; u16 count; u32 *nodes; } SSNodeList;
u32 *SSNodeList_GetNextNode(SSNodeList *list) {
    u16 idx = list->count;
    u32 *node = &list->nodes[idx];

    list->count = idx + 1;
    if (list->count >= list->capacity) {
        return NULL;
    }
    return node;
}
