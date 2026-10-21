// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct BootNode {
    struct BootNode *next;
    struct BootNode *prev;
    u64 interval;
    u64 remaining;
    s32 mq;
    s32 msg;
} BootNode;

extern BootNode *D_80098160;
extern u32 D_8009E990;

s32 func_80091C00(void);
void func_80091C70(s32 a);
u32 func_8008D460(void);
u64 func_8008F7E4(BootNode *p);
void func_8008F744(u32 hi, u32 lo);

s32 func_800942F0(BootNode *node, u64 value, u64 interval, s32 mq, s32 msg) {
    u64 sp30;
    BootNode *q;
    u32 now;
    u32 delta;
    s32 sp20;
    u64 *p;

    node->next = NULL;
    node->prev = NULL;
    node->interval = interval;
    if (value != 0) {
        node->remaining = value;
    } else {
        node->remaining = interval;
    }
    node->mq = mq;
    node->msg = msg;
    sp20 = func_80091C00();
    if (D_80098160->next == D_80098160) {} else {
        q = D_80098160->next;
        now = func_8008D460();
        delta = now - D_8009E990;
        if ((u64)delta < q->remaining) {
            p = &q->remaining;
            *p = *p - (u64)delta;
        } else {
            q->remaining = 1;
        }
    }
    sp30 = func_8008F7E4(node);
    func_8008F744(*(u32 *)&D_80098160->next->remaining, *((u32 *)&D_80098160->next->remaining + 1));
    func_80091C70(sp20);
    return 0;
}
