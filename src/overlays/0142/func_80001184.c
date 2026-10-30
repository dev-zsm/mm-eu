#include "types.h"
extern void func_800BDD44();
extern u32 D_8090BED8[];
typedef struct { u8 pad0[0x1C]; s16 v; } A;
void func_80001184(A *a, s32 b) {
    func_800BDD44(b, D_8090BED8[(a->v >> 15) & 1]);
}
