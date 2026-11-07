#include "types.h"
typedef struct { u8 p0[0x1C]; s16 u1C; u8 p1[0x13E]; void *u15C; s32 u160; } A;
extern u8 D_80AA9964[];
void func_80000328(A *a) {
    a->u160 = a->u1C; // swapped store order matches scheduling
    a->u15C = D_80AA9964;
}
