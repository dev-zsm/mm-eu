#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A61EC0[];
void func_80A61610(u8 *a, s32 b);
void func_800B8C4C(u8 *a, s32 b);

void func_80000854(u8 *a) {
    func_80A61610(a, 0);
    M2C_FIELD(a, u32 *, 4) &= ~0x08000000;
    M2C_FIELD(a, s16 *, 0x2B2) = 1;
    func_800B8C4C(a, 0x3A07);
    M2C_FIELD(a, void **, 0x2A8) = D_80A61EC0;
}
