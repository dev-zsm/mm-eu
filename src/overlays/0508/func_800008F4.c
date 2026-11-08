#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0508.h"
extern f32 D_80B5C3B4;
f32 func_800FEB84(s16 a);

void func_800008F4(u8 *a) {
    M2C_FIELD(a, s16 *, 0x392) = func_800FEB84(M2C_FIELD(a, s16 *, 0x388)) * 30.0f * D_80B5C3B4;
    M2C_FIELD(a, s16 *, 0x388) += 0x400;
}
