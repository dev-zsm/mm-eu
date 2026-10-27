// FLAGS: -O2 -g3 -mips2 -trapuv
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

void func_80081A50(Node *client, u32 a1, u32 a2, u32 a3) {
    u32 mask;
    s32 isRegistered = 0;

    mask = osSetIntMask(1);
    {
        Node *iter = D_8009C220->head;

        while (iter != NULL) {
            if (iter == client) {
                isRegistered = 1;
                goto end;
            }
            iter = iter->next;
        }
    }
    client->unk4 = a1;
    client->unk8 = a2;
    client->unkC = a3;
    client->next = D_8009C220->head;
    D_8009C220->head = client;
end:
    osSetIntMask(mask);
    if (isRegistered) {
        func_8008198C(D_80098744, client);
    }
}
