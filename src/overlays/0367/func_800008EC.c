#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A61F44[];
void func_80A61610(u8 *a, s32 b);
void func_80A61988(u8 *a);

void func_800008EC(u8 *a) {
    func_80A61610(a, 1);
    M2C_FIELD(a, s32 *, 0x37C) = 0;
    func_80A61988(a);
    M2C_FIELD(a, s16 *, 0x2B2) = 2;
    M2C_FIELD(a, void **, 0x2A8) = D_80A61F44;
}
