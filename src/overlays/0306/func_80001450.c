#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A0D6F8[];
void func_800B8C4C(u8 *a, s32 b);

void func_80001450(u8 *a) {
    func_800B8C4C(a, 0x392D);
    M2C_FIELD(a, s16 *, 0xC0) = 0;
    M2C_FIELD(a, u8 *, 0x2C0) &= ~1;
    M2C_FIELD(a, u32 *, 0x2D0) = 0xF7CFFFFF;
    M2C_FIELD(a, void **, 0x298) = D_80A0D6F8;
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
}
