#include "types.h"
typedef struct { u8 pad[0x2EC]; void *f; } A;
extern s32 D_80B33670;
extern u8 D_80B2BF10[];
void func_80003810(A *x) { D_80B33670 = 3; x->f = D_80B2BF10; }
