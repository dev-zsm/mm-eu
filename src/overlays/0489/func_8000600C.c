#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_80B2E730[];
extern f32 D_80B33C98;
extern f32 D_80B33C9C;

void func_8000600C(u8 *a) {
    M2C_FIELD(a, s16 *, 0x2F0) = 0x28;
    M2C_FIELD(a, f32 *, 0x3A0) = D_80B33C98;
    M2C_FIELD(a, f32 *, 0x3A4) = D_80B33C9C;
    M2C_FIELD(a, s16 *, 0x3AA) = 0xBB8;
    M2C_FIELD(a, void **, 0x2EC) = D_80B2E730;
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
}
