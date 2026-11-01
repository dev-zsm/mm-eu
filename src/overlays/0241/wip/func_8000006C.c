#include "types.h"

extern u8 D_8097F138;

void func_8000006C(s32 a0, u8 *a1) {
    u8 *src = &D_8097F138 + a0 * 3;

    a1[0] = src[0];
    a1[1] = src[1];
    a1[2] = src[2];
}
