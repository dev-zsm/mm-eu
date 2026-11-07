#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B72748[];
void func_80B72AA8(u8 *a, s32 b, s32 c);

void func_800009B4(u8 *a) {
    M2C_FIELD(a, u32 *, 4) |= 0x10;
    func_80B72AA8(a, 0, 0);
    M2C_FIELD(a, void **, 0x188) = D_80B72748;
}
