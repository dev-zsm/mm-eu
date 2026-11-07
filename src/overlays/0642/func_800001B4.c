#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BFE854[];
extern u8 D_80BFF850[];
void func_800FF8DC(u8 *a, u8 *b);

void func_800001B4(u8 *a, s32 b) {
    func_800FF8DC(a, D_80BFF850);
    M2C_FIELD(a, void **, 0x144) = D_80BFE854;
    M2C_FIELD(a, u32 *, 0x164) |= 1;
}
