#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B4803C[];
void func_800B64E0(u8 *a, f32 b);

void func_80001CDC(u8 *a) {
    M2C_FIELD(a, f32 *, 0x218) = M2C_FIELD(a, f32 *, 0x28);
    func_800B64E0(a, -10.0f);
    M2C_FIELD(a, s16 *, 0x206) = 0x190;
    M2C_FIELD(a, u32 *, 4) |= 1;
    M2C_FIELD(a, void **, 0x200) = D_80B4803C;
}
