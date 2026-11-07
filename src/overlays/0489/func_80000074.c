#include "types.h"
#include "m2c_compat.h"
extern u32 D_801E7D78[];

s32 func_80000074(s32 x) {
    u32 v;

    if (!(x & 1)) {
        v = D_801E7D78[x >> 1] & 0xFFFF;
    } else {
        v = (D_801E7D78[x >> 1] & 0xFFFF0000) >> 16;
    }
    return v + 0x1AAA;
}
