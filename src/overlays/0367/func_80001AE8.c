#include "types.h"
#include "m2c_compat.h"
extern u8 D_80A63134[];
void func_80A61610(u8 *a, s32 b);

void func_80001AE8(u8 *a) {
    func_80A61610(a, 2);
    M2C_FIELD(a, s16 *, 0x2B2) = 5;
    M2C_FIELD(a, void **, 0x2A8) = D_80A63134;
}
