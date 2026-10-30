#include "types.h"

typedef struct { u8 p0[0x1C]; s16 u1C; } A;
extern void func_800BDD44();
extern s32 D_80AFE7B8[];

void func_80002E98(A *a, s32 b) {
    func_800BDD44(b, D_80AFE7B8[a->u1C], b, a);
}
