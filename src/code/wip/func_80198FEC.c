// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Node {
    /* 0x00 */ u32 pad0 : 3;
    /* 0x00 */ u32 a : 1;
    /* 0x00 */ u32 b : 1;
    /* 0x00 */ u32 pad1 : 1;
    /* 0x00 */ u32 c : 1;
    /* 0x00 */ u32 pad2 : 25;
    /* 0x04 */ u8 pad4[0x38];
    /* 0x3C */ struct Node *unk3C;
    /* 0x40 */ u8 pad40[8];
    /* 0x48 */ struct Node *unk48;
    /* 0x4C */ u8 pad4C[0x10];
    /* 0x5C */ s32 unk5C;
} Node;

void func_80196AD0(Node *, s32);
void func_80196C14(Node *, Node *);
Node *func_80197480(Node *);
void func_80197ED8(Node *);
void func_80197FC8(Node *);

s32 func_80198FEC(Node *arg0, s32 arg1) {
    Node *p;

    if (arg0->a == 1 && arg0->c == 1) {
        return 0;
    }
    if (arg0->a == 1 && (p = arg0->unk3C) != NULL && arg0->b && arg1 == 1 && arg0 == p->unk48) {
        if (arg0->unk5C == 0) {
            func_80196C14(p, arg0);
        }
    } else {
        if (arg1 == 0) {
            func_80196AD0(arg0, 1);
        }
        p = func_80197480(arg0);
        arg0->unk3C = p;
        if (p != NULL && arg0 == p->unk48) {
            func_80197ED8(p);
        }
    }
    p = arg0->unk3C;
    if (p != NULL && arg0 == p->unk48) {
        func_80197FC8(p);
    }
    return 0;
}
