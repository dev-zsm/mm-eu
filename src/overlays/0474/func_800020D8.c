#include "types.h"
#include "m2c_compat.h"
extern s32 D_80B10014;
extern u8 D_80B0F1C8[];
void func_80B0D0A0(u8 *a, s32 b);

void func_800020D8(u8 *a) {
    func_80B0D0A0(a, 4);
    M2C_FIELD(a, s16 *, 0x2B6) = M2C_FIELD(a, s16 *, 0x2B4) = 0;
    M2C_FIELD(a, s32 *, 0x2C4) = 0;
    D_80B10014 = 2;
    M2C_FIELD(a, void **, 0x2A8) = D_80B0F1C8;
}
