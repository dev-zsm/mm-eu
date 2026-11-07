#include "types.h"
typedef struct { s32 x, y, z; } V3;
typedef struct { V3 v; s32 aC; s32 a10; s32 a14; s32 a18; s32 a1C; } A;
void func_8000000C(A *a, s32 b, V3 *c) {
    a->v = *c;
    a->aC = 0;
    a->a10 = 0;
    a->a14 = 0;
    a->a18 = 0;
    a->a1C = 0;
}
