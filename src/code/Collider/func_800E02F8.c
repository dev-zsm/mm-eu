// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} ColliderInit;

extern ColliderInit D_801BAD70;

s32 Collider_InitBase(s32 arg0, ColliderInit *arg1) {
    *arg1 = D_801BAD70;
    return 1;
}
