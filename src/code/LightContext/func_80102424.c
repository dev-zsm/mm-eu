#include "types.h"

typedef struct LightNode {
    /* 0x0 */ void *info;
    /* 0x4 */ struct LightNode *prev;
    /* 0x8 */ struct LightNode *next;
} LightNode;

extern LightNode *Lights_FindBufSlot(void);

LightNode *LightContext_InsertLight(void *play, LightNode **listHead, void *info) {
    LightNode *node = Lights_FindBufSlot();

    if (node != NULL) {
        node->info = info;
        node->prev = NULL;
        node->next = *listHead;
        if (*listHead != NULL) {
            (*listHead)->prev = node;
        }
        *listHead = node;
    }
    return node;
}
