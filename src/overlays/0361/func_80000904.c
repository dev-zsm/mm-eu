#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A55D50[];
void func_800B8C4C(u8 *a, s32 b);

void func_80000904(u8 *a, s32 b) {
    M2C_FIELD(a, f32 *, 0x160) = M2C_FIELD(a, f32 *, 0x164) = 0.0f;
    M2C_FIELD(a, f32 *, 0x28) = M2C_FIELD(a, f32 *, 0xC);
    func_800B8C4C(a, 0x2893);
    M2C_FIELD(a, void **, 0x15C) = D_80A55D50;
}
