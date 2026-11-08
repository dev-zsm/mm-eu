#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0510.h"
extern u8 D_80B61A48[];
void func_800B8C4C(u8 *a, s32 b);

void func_80000450(u8 *a) {
    M2C_FIELD(a, f32 *, 0x2F8) = 0.0f;
    M2C_FIELD(a, f32 *, 0x160) = 2.0f;
    func_800B8C4C(a, 0x3987);
    M2C_FIELD(a, void **, 0x2AC) = D_80B61A48;
}
