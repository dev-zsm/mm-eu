#include "types.h"

typedef struct GameAllocNode {
    struct GameAllocNode *next;
    struct GameAllocNode *prev;
    s32 size;
} GameAllocNode;

typedef struct {
    GameAllocNode *unk0;
    GameAllocNode *unk4;
    u8 pad8[8];
    GameAllocNode *unk10;
} GameAlloc;

extern GameAllocNode *func_80086E40(s32 size);

void *GameAlloc_Malloc(GameAlloc *alloc, s32 size) {
    GameAllocNode *node = func_80086E40(size + 0x10);

    if (node != NULL) {
        node->size = size;
        node->prev = alloc->unk10;
        alloc->unk10->next = node;
        alloc->unk10 = node;
        node->next = (GameAllocNode *)alloc;
        alloc->unk4 = alloc->unk10;
        return (u8 *)node + 0x10;
    }
    return NULL;
}
