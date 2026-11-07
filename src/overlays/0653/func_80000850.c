#include "types.h"
#include "m2c_compat.h"
extern u8 D_80C05330[];
void func_800B8C4C(u8 *a, s32 b);

void func_80000850(u8 *a) {
    if (M2C_FIELD(a, u16 *, 0x90) & 1) {
        M2C_FIELD(a, f32 *, 0x70) = 0.0f;
    }
    func_800B8C4C(a, 0x389E);
    M2C_FIELD(a, void **, 0x228) = D_80C05330;
}
