#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_80B2E184[];
extern f32 D_80B33C50;
extern f32 D_80B33C54;

void func_80005A54(u8 *a) {
    M2C_FIELD(a, s16 *, 0x2F0) = 0x78;
    M2C_FIELD(a, f32 *, 0x3A0) = D_80B33C50;
    M2C_FIELD(a, f32 *, 0x3A4) = D_80B33C54;
    M2C_FIELD(a, f32 *, 0x74) = 33.0f;
    M2C_FIELD(a, s16 *, 0x3AA) = 0xBB8;
    M2C_FIELD(a, u8 *, 0x3AC) = 0;
    M2C_FIELD(a, s16 *, 0x2F2) = 0;
    M2C_FIELD(a, void **, 0x2EC) = D_80B2E184;
}
