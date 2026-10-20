// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    s32 unk1C;
} Node;

extern u8 D_8009B690[];

void func_80088070(void *a, Node **out, s32 c);
void func_80080A58(Node *node);
void func_80087CB0(s32 a, s32 b, s32 c);

void func_80080BD4(s32 arg0) {
    Node *node;
    Node *p;

    for (;;) {
        func_80088070(D_8009B690, &node, 1);
        if (node == NULL) {
            break;
        }
        p = node;
        func_80080A58(p);
        if (p->unk18 != 0) {
            func_80087CB0(p->unk18, p->unk1C, 0);
        }
    }
}
