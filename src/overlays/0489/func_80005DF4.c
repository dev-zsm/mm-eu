#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"
extern u8 D_80B2E51C[];
extern f32 D_80B33C80;
extern f32 D_80B33C84;

void func_80005DF4(Actor *thisx) {
    M2C_FIELD(thisx, f32 *, 0x3A0) = D_80B33C80;
    M2C_FIELD(thisx, f32 *, 0x3A4) = D_80B33C84;
    M2C_FIELD(thisx, s16 *, 0x3AA) = 0xBB8;
    M2C_FIELD(thisx, s16 *, 0x2F0) = 0x23;
    M2C_FIELD(thisx, void **, 0x2EC) = D_80B2E51C;
    M2C_FIELD(thisx, f32 *, 0x74) = -1.5f;
}
