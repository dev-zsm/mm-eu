#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B6C014[];
void func_80B6AB38(u8 *a, s32 b);

void func_80001D14(u8 *a) {
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
    func_80B6AB38(a, 0);
    M2C_FIELD(a, s16 *, 0x2B0) = 1;
    M2C_FIELD(a, void **, 0x2AC) = D_80B6C014;
    M2C_FIELD(a, f32 *, 0xCC) = 90.0f;
}
