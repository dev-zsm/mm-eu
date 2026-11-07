#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BF2124[];
void func_800B8C4C(u8 *a, s32 b);
void func_80BF0030(u8 *a, s32 b);

void func_800020A4(u8 *a) {
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
    func_800B8C4C(a, 0x3AA4);
    func_80BF0030(a, 6);
    M2C_FIELD(a, s16 *, 0x2B4) = 0xB;
    M2C_FIELD(a, void **, 0x284) = D_80BF2124;
}
