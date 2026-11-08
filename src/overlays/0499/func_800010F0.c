#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0499.h"
extern u8 D_80B4CDD8[];
extern u8 D_80B4D1CC[];
s32 func_8012F5DC(s32 a);

void func_800010F0(u8 *a, u8 *play) {
    if (func_8012F5DC(M2C_FIELD(play, s16 *, 0xA4)) >= 0x1E) {
        M2C_FIELD(a, void **, 0x138) = D_80B4CDD8;
        M2C_FIELD(a, void **, 0x13C) = D_80B4D1CC;
        M2C_FIELD(a, u32 *, 4) |= 1;
    }
}
