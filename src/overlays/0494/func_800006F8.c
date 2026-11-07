#include "types.h"
#include "m2c_compat.h"
extern u8 D_80B43D00[];
void func_800B8C4C(u8 *a, s32 b);

void func_800006F8(u8 *a) {
    M2C_FIELD(a, s16 *, 0x2B0) = M2C_FIELD(a, s16 *, 0x2BE) = 0;
    func_800B8C4C(a, 0x3963);
    M2C_FIELD(a, s16 *, 0x2AE) = 0xFA;
    M2C_FIELD(a, void **, 0x248) = D_80B43D00;
}
