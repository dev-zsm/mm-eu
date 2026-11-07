#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B2E51C[];
extern f32 D_80B33C80;
extern f32 D_80B33C84;

void func_80005DF4(u8 *a) {
    M2C_FIELD(a, f32 *, 0x3A0) = D_80B33C80;
    M2C_FIELD(a, f32 *, 0x3A4) = D_80B33C84;
    M2C_FIELD(a, s16 *, 0x3AA) = 0xBB8;
    M2C_FIELD(a, s16 *, 0x2F0) = 0x23;
    M2C_FIELD(a, void **, 0x2EC) = D_80B2E51C;
    M2C_FIELD(a, f32 *, 0x74) = -1.5f;
}
