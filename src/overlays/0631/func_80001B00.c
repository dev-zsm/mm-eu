#include "types.h"
#include "m2c_compat.h"
extern u8 D_80BF1B84[];
void func_800B8C4C(u8 *a, s32 b);
void func_80BF0030(u8 *a, s32 b);

void func_80001B00(u8 *a) {
    M2C_FIELD(a, s32 *, 0x2A4) = 0;
    M2C_FIELD(a, f32 *, 0x70) = 0.0f;
    func_800B8C4C(a, 0x3AAA);
    func_80BF0030(a, 5);
    M2C_FIELD(a, s16 *, 0x2B4) = 6;
    M2C_FIELD(a, void **, 0x284) = D_80BF1B84;
}
