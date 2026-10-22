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

void *__osDisableInt(void *a0);
void __osRestoreInt(void *a0);

void osViSetMode(Sub *a0) {
    void *v;

    v = __osDisableInt(a0);
    D_800982B4->unk8 = a0;
    D_800982B4->unk0 = 1;
    D_800982B4->unkC = D_800982B4->unk8->unk4;
    __osRestoreInt(v);
}
