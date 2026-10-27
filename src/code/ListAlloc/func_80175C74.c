#include "types.h"

typedef struct ListAllocNode {
    /* 0x0 */ struct ListAllocNode *prev;
    /* 0x4 */ struct ListAllocNode *next;
} ListAllocNode;

typedef struct {
    /* 0x0 */ ListAllocNode *first;
    /* 0x4 */ ListAllocNode *last;
} ListAlloc;

extern void *func_80086E40(s32 size);

void *ListAlloc_Alloc(ListAlloc *this, s32 size) {
    ListAllocNode *node = func_80086E40(size + 8);
    ListAllocNode *last;

    if (node == NULL) {
        return NULL;
    }
    last = this->last;
    if (last != NULL) {
        last->next = node;
    }
    node->prev = last;
    node->next = NULL;
    this->last = node;
    if (this->first == NULL) {
        this->first = node;
    }
    return (u8 *)node + 8;
}
