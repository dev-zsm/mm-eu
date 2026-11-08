#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0517.h"
extern u8 D_80B6D684[];
void func_80B6AB38(u8 *a, s32 b);

void func_80003380(u8 *a) {
    func_80B6AB38(a, 0xA);
    M2C_FIELD(a, u8 *, 0x430) &= ~6;
    M2C_FIELD(a, s16 *, 0x2D0) = 0;
    M2C_FIELD(a, s16 *, 0x2B0) = 0xB;
    M2C_FIELD(a, void **, 0x2AC) = D_80B6D684;
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
}
