// FLAGS: -O2 -g3
#include "types.h"

typedef struct Node {
    struct Node *next;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} Node;

typedef struct Owner {
    u8 pad0[0x7D8];
    Node *head;
} Owner;

extern u32 osSetIntMask(u32 mask);
extern void func_8008198C(void *queue, void *node);
extern Owner *D_8009C220;
extern u8 D_80098744[];

void func_80081A50(Node *node, u32 a1, u32 a2, u32 a3) {
    s32 found;
    u32 saved;
    Node *p;

    found = 0;
    saved = osSetIntMask(1);
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
        node->unkC = a3;
        node->next = D_8009C220->head;
        D_8009C220->head = node;
    }
    osSetIntMask(saved);
    if (found) {
        func_8008198C(D_80098744, node);
    }
}
