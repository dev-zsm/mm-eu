// FLAGS: -O2 -g3
#include "types.h"

s32 func_800881B0(s32);
void func_80087CB0(s32, void *, s32);

typedef struct Node {
    struct Node *next;
    s32 data;
} Node;

typedef struct Owner {
    u8 pad0[0x248];
    Node *list;
    u8 count;
} Owner;

void func_800812A0(Owner *arg0, Node *arg1, s32 arg2) {
    s32 irq;

    irq = func_800881B0(1);
    arg1->data = arg2;
    arg1->next = arg0->list;
    arg0->list = arg1;
    func_800881B0(irq);
    if (arg0->count > 0) {
        func_80087CB0(arg1->data, (u8 *)arg0 + 0x20, 0);
    }
    if (arg0->count >= 2) {
        func_80087CB0(arg1->data, (u8 *)arg0 + 0x40, 0);
    }
}
