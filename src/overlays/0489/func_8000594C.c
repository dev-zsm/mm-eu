#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B2E07C[];
extern f32 D_80B33C40;
extern f32 D_80B33C44;
extern f32 D_80B33C48;

void func_8000594C(u8 *a) {
    M2C_FIELD(a, f32 *, 0x68) *= D_80B33C40;
    M2C_FIELD(a, s16 *, 0x2F0) = 0x14;
    M2C_FIELD(a, f32 *, 0x3A0) = D_80B33C44;
    M2C_FIELD(a, f32 *, 0x3A4) = D_80B33C48;
    M2C_FIELD(a, s16 *, 0x3AA) = 0xBB8;
    M2C_FIELD(a, void **, 0x2EC) = D_80B2E07C;
}
