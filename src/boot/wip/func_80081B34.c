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

extern u32 func_800881B0(u32 mask);
extern void func_8008198C(void *queue, void *node);
extern Owner *D_8009C220;
extern u8 D_8009877C[];

void func_80081B34(Node *node) {
    Owner *g;
    Node *prev;
    Node *cur;
    s32 flag;
    u32 saved;

    g = D_8009C220;
    prev = NULL;
    flag = 0;
    cur = g->head;
    saved = func_800881B0(1);
    if (cur != NULL) {
        do {
            if (cur == node) {
                if (prev == NULL) {
                    g->head = node->next;
                    flag = (g->head == NULL);
                } else {
                    prev->next = node->next;
                }
                break;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != NULL);
    }
    func_800881B0(saved);
    if (flag) {
        func_8008198C(D_8009877C, node);
    }
}
