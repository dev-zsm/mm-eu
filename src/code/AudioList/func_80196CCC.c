#include "types.h"

typedef struct Node {
    struct Node *prev;
    struct Node *unk4;
    struct Node *next;
    u8 pad[0xF8 - 0xC];
} Node;

typedef struct {
    u8 pad0[0x28B8];
    s32 count;
    u8 pad28BC[0x445C - 0x28BC];
    Node *nodes;
} AudioCtx;

extern AudioCtx D_801F84B0;
extern u8 D_801FFDE8[];
void AudioList_InitNoteLists(u8 *);
void AudioList_PushBack(u8 *, Node *);

void AudioList_InitNoteFreeList(void) {
    s32 i;

    AudioList_InitNoteLists(D_801FFDE8);
    for (i = 0; i < D_801F84B0.count; i++) {
        D_801F84B0.nodes[i].next = &D_801F84B0.nodes[i];
        D_801F84B0.nodes[i].prev = 0;
        AudioList_PushBack(D_801FFDE8, &D_801F84B0.nodes[i]);
    }
}
