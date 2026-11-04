// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { f32 x, y, z; } V3;
f32 func_8008704C();
f32 Math_CosS(s16);
f32 Math_SinS(s16);
void func_800B18F8(V3 *arg0, f32 arg1, V3 *arg2, V3 *arg3, V3 *arg4) {
    s16 sp26;
    f32 sp20;

    sp20 = func_8008704C() * arg1;
    sp26 = func_8008704C() * 65536.0f;
    *arg2 = *arg0;
    arg2->x += Math_SinS(sp26) * sp20;
    arg2->z += Math_CosS(sp26) * sp20;
    arg3->y = 1.0f;
    arg3->x = Math_SinS(sp26);
    arg3->z = Math_CosS(sp26);
    arg4->x = 0.0f;
    arg4->y = 0.0f;
    arg4->z = 0.0f;
}
