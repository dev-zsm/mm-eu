// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct Node {
    struct Node *next;
    u32 unk4;
    u32 unk8;
    u32 unkC;
} Node;

typedef struct Owner {
    u8 pad0[0x7DC];
    Node *head;
} Owner;

extern u32 osSetIntMask(u32 mask);
extern void func_8008198C(void *queue, void *node);
extern Owner *D_8009C220;
extern u8 D_800987FC[];

void Fault_RemoveAddrConvClient(Node *client) {
    Node *iter;
    Node *lastIter;
    u32 mask;
    s32 listIsEmpty;

    iter = D_8009C220->head;
    lastIter = NULL;
    listIsEmpty = 0;
    mask = osSetIntMask(1);
    while (iter != NULL) {
        if (iter == client) {
            if (lastIter != NULL) {
                lastIter->next = client->next;
            } else {
                D_8009C220->head = client;
                if (D_8009C220->head != NULL) {
                    D_8009C220->head = client->next;
                } else {
                    listIsEmpty = 1;
                }
            }
            break;
        }
        lastIter = iter;
        iter = iter->next;
    }
    osSetIntMask(mask);
    if (listIsEmpty) {
        func_8008198C(D_800987FC, client);
    }
}
