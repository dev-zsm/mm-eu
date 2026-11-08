#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0510.h"
extern u8 D_80B61D1C[];
void func_800B8C4C(u8 *a, s32 b);

void func_80000710(u8 *a) {
    func_800B8C4C(a, 0x398A);
    M2C_FIELD(a, s16 *, 0x30C) = 0xA;
    M2C_FIELD(a, s16 *, 0x30A) = 0x3C;
    M2C_FIELD(a, void **, 0x2AC) = D_80B61D1C;
    M2C_FIELD(a, f32 *, 0x160) = 2.0f;
    M2C_FIELD(a, f32 *, 0x70) = 14.0f;
}
