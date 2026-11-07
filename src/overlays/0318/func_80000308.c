#include "types.h"
#include "m2c_compat.h"
extern u8 D_600466C[];
extern u8 D_80A1B0A0[];
void func_80137884(u8 *a, u8 *b, f32 c);
void func_800B6564(u8 *a, f32 b);

void func_80000308(u8 *a) {
    func_80137884(a + 0x144, D_600466C, 0.0f);
    M2C_FIELD(a, s32 *, 0x13C) = 0;
    func_800B6564(a, 0.01f);
    M2C_FIELD(a, void **, 0x188) = D_80A1B0A0;
}
