// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Node {
    struct Node *next;
    void *data;
} Node;

typedef struct Ent {
    u8 pad0[8];
    s32 unk8;
    u8 pad1[4];
    s32 unk10;
} Ent;

typedef struct Obj {
    u8 pad0[0x248];
    Node *list;
} Obj;

extern void func_80087CB0(void *a, u32 b, u32 c);

void func_80081408(Obj *arg0, u32 arg1) {
    Node *n;
    Ent *e;

    n = arg0->list;
    if (n != NULL) {
        do {
            e = n->data;
            if (e->unk8 < e->unk10) {
                func_80087CB0(e, arg1, 0);
            }
            n = n->next;
        } while (n != NULL);
    }
}
