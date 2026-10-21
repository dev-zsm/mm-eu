// FLAGS: -O1 -g3 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    u32 unk8;
    u32 unkC;
    u64 val;
    void *unk18;
    u32 unk1C;
} Node;

extern Node *D_80098160;
extern u32 D_8009E990;
extern u32 func_8008D460(void);
extern void func_80091420(u32 a);
extern void func_8008F744(u64 v);
extern void func_80087CB0(void *a, u32 b, s32 c);
extern void func_8008F7E4(Node *p);

void func_8008F5CC(void) {
    Node *q;
    u32 now;
    u32 delta;

    if (D_80098160->next == D_80098160) {
        return;
    }
    for (;;) {
        q = D_80098160->next;
        if (q == D_80098160) {
            func_80091420(0);
            D_8009E990 = 0;
            return;
        }
        now = func_8008D460();
        delta = now - D_8009E990;
        D_8009E990 = now;
        if ((u64)delta < q->val) {
            q->val -= delta;
            func_8008F744(q->val);
            return;
        }
        q->prev->next = q->next;
        q->next->prev = q->prev;
        q->next = NULL;
        q->prev = NULL;
        if (q->unk18 != NULL) {
            func_80087CB0(q->unk18, q->unk1C, 0);
        }
        if (q->unk8 != 0 || q->unkC != 0) {
            q->val = *(u64 *)&q->unk8;
            func_8008F7E4(q);
        }
    }
}
