// FLAGS: -O1 -g3 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    u32 unk8;
    u32 unkC;
    u64 val;
} Node;

extern Node *D_80098160;
extern void *func_80091C00(void);
extern void func_80091C70(void *a);

void func_8008F7E4(Node *p) {
    Node *q;
    u64 rem;
    void *s;
    s = func_80091C00();
    rem = p->val;
    q = D_80098160->next;
    if (q != D_80098160 && q->val < rem) {
        do {
            rem -= q->val;
            q = q->next;
        } while (q != D_80098160 && q->val < rem);
    }
    p->val = rem;
    if (q != D_80098160) {
        q->val -= rem;
    }
    p->next = q;
    p->prev = q->prev;
    q->prev->next = p;
    q->prev = p;
    func_80091C70(s);
}
