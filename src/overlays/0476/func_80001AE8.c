#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B12F60[];
void func_800B64E0(u8 *a, f32 b);

void func_80001AE8(u8 *a) {
    M2C_FIELD(a, f32 *, 0xC) = M2C_FIELD(a, f32 *, 0x28);
    func_800B64E0(a, -10.0f);
    M2C_FIELD(a, s16 *, 0x18E) = 0xC8;
    M2C_FIELD(a, u8 *, 0x18D) = 0x20;
    M2C_FIELD(a, u32 *, 4) |= 1;
    M2C_FIELD(a, void **, 0x188) = D_80B12F60;
}
