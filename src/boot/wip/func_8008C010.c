// FLAGS: -O2 -g3
#include "types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    u32 unk8;
    u32 unkC;
    u32 hi;
    u32 lo;
} Node;

extern Node *D_80098160;
extern void *func_80091C00(void);
extern void func_80091420(s32 a);
extern void func_80091C70(void *a);

s32 func_8008C010(Node *p) {
    Node *q;
    u32 *d;
    void *s;
    u32 lo;

    if (p->next == NULL) {
        return -1;
    }
    s = func_80091C00();
    q = p->next;
    if (q != D_80098160) {
        d = &q->hi;
        lo = d[1] + p->lo;
        d[0] = d[0] + p->hi + (lo < p->lo);
        d[1] = lo;
    }
    p->next->prev = p->prev;
    p->prev->next = p->next;
    p->next = NULL;
    p->prev = NULL;
    if (D_80098160->next == D_80098160) {
        func_80091420(0);
    }
    func_80091C70(s);
    return 0;
}
