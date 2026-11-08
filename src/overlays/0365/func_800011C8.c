#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0365.h"
extern u8 D_80A5D264[];
void func_80A5C360(u8 *a, s32 b);

void func_800011C8(u8 *a) {
    M2C_FIELD(a, s32 *, 0x36C) = 2;
    M2C_FIELD(a, u8 *, 0xF05) |= 4;
    M2C_FIELD(a, u32 *, 4) &= ~0x100000;
    func_80A5C360(a, 0xD);
    M2C_FIELD(a, void **, 0x278) = D_80A5D264;
}
