#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A0E39C[];
extern u8 D_80A0D39C[];
void func_800B8C4C(u8 *a, s32 b);

void func_800010F8(u8 *a) {
    M2C_FIELD(a, void **, 0x13C) = D_80A0E39C;
    M2C_FIELD(a, f32 *, 0x2A8) = 0.5f;
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
    func_800B8C4C(a, 0x392B);
    M2C_FIELD(a, void **, 0x298) = D_80A0D39C;
}
