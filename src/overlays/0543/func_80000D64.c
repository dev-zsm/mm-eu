#include "types.h"
#include "m2c_compat.h"
extern f32 D_80B937A4;
f32 func_800FEB84(s16 a);

void func_80000D64(u8 *a) {
    M2C_FIELD(a, s16 *, 0x3F2) = func_800FEB84(M2C_FIELD(a, s16 *, 0x3F4)) * 60.0f * D_80B937A4;
    M2C_FIELD(a, s16 *, 0x3F4) += 0x400;
}
