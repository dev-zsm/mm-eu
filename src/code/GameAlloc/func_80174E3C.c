#include "types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    s32 pad[2];
} Node;

typedef struct {
    s32 pad0;
    s32 head;
    s32 pad8[2];
    s32 unk10;
} GameAlloc;

extern void func_80086EC0(Node *node);

void GameAlloc_Free(GameAlloc *alloc, void *ptr) {
    Node *node;

    if (ptr != NULL) {
        node = (Node *)ptr - 1;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        alloc->unk10 = alloc->head;
        func_80086EC0(node);
    }
}
