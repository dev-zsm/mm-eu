#include "types.h"
typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
    u8 pad1E[0x15C - 0x1E];
    void *unk15C;
    u8 pad160[0x16A - 0x160];
    s8 unk16A;
} A;
extern s8 D_80B7768C[][0x1C];
extern u8 D_80B772D8[];
void func_8000065C(A *a) {
    s32 i = (a->unk1C >> 8) & 3;
    a->unk16A = D_80B7768C[i][0];
    a->unk15C = D_80B772D8;
}
