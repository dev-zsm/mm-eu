// FLAGS: -O2 -g3
#include "types.h"

typedef struct Node {
    struct Node *next;
    u32 unk4;
    u32 unk8;
} Node;

typedef struct Owner {
    u8 pad0[0x7DC];
    Node *head;
} Owner;

extern u32 func_800881B0(u32 mask);
extern void func_8008198C(void *queue, void *node);
extern Owner *D_8009C220;
extern u8 D_800987B4[];

void func_80081C2C(Node *node, u32 a1, u32 a2) {
    s32 found;
    u32 saved;
    Node *p;

    found = 0;
    saved = func_800881B0(1);
    p = D_8009C220->head;
    if (p != NULL) {
        do {
            if (p == node) {
                found = 1;
                break;
            }
            p = p->next;
        } while (p != NULL);
    }
    if (!found) {
        node->unk4 = a1;
        node->unk8 = a2;
        node->next = D_8009C220->head;
        D_8009C220->head = node;
    }
    func_800881B0(saved);
    if (found) {
        func_8008198C(D_800987B4, node);
    }
}
