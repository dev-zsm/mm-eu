#include "types.h"

typedef struct LightNode {
    void *info;
    struct LightNode *prev;
    struct LightNode *next;
} LightNode;

extern void LightContext_RemoveLight(s32 a0, LightNode **list, LightNode *node);

void LightContext_DestroyList(s32 a0, LightNode **list) {
    LightNode *node = *list;

    while (node != NULL) {
        LightContext_RemoveLight(a0, list, node);
        *list = (*list)->next;
        node = *list;
    }
}
