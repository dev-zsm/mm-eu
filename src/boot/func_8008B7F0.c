// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Sub {
    u8 pad0[4];
    s32 unk4;
} Sub;

typedef struct Obj {
    s16 unk0;
    u8 pad2[6];
    Sub *unk8;
    s32 unkC;
} Obj;

extern Obj *D_800982B4;

void *func_80091C00(void *a0);
void func_80091C70(void *a0);

void func_8008B7F0(Sub *a0) {
    void *v;

    v = func_80091C00(a0);
    D_800982B4->unk8 = a0;
    D_800982B4->unk0 = 1;
    D_800982B4->unkC = D_800982B4->unk8->unk4;
    func_80091C70(v);
}
