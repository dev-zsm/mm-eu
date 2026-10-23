// FLAGS: -O2 -g3 -mips2 -trapuv
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

extern u32 osSetIntMask(u32 mask);
extern void func_8008198C(void *queue, void *node);
extern Owner *D_8009C220;
extern u8 D_800987B4[];

void Fault_AddAddrConvClient(Node *node, u32 a1, u32 a2) {
    Node *p;
    s32 found;
    u32 saved;

    found = 0;
    saved = osSetIntMask(1);
    p = D_8009C220->head;
    if (p != NULL) {
        do {
            if (p == node) {
                found = 1;
                goto done;
            }
            p = p->next;
        } while (p != NULL);
    }
    node->unk4 = a1;
    node->unk8 = a2;
    node->next = D_8009C220->head;
    D_8009C220->head = node;
done:
    osSetIntMask(saved);
    if (found) {
        func_8008198C(D_800987B4, node);
    }
}
