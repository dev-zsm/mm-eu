#include "types.h"
#include "m2c_compat.h"
extern u8 D_600466C[];
extern u8 D_80A1AFF8[];
void func_80137884(u8 *a, u8 *b, f32 c, u8 *d);

void func_80000270(u8 *a) {
    func_80137884(a + 0x144, D_600466C, 0.0f, a);
    M2C_FIELD(a, s32 *, 0x13C) = 0;
    M2C_FIELD(a, void **, 0x188) = D_80A1AFF8;
}
