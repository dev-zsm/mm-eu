#include "types.h"
#include "m2c_compat.h"
extern u8 D_80AECFDC[];
s32 func_800F1F68(s32 a);
void func_801667DC(s32 a);

void func_80002FCC(u8 *a) {
    M2C_FIELD(a, s16 *, 0x19C) = 0x64;
    M2C_FIELD(a, s16 *, 0x1AC) = func_800F1F68(M2C_FIELD(a, s8 *, 0x38));
    func_801667DC(0x8C);
    M2C_FIELD(a, void **, 0x188) = D_80AECFDC;
}
