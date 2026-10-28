// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern f32 D_80901E8C;
extern s16 D_80901E90;

void func_80000084(void) {
    D_80901E8C = 0.0f;
    D_80901E90 = 0;
}
