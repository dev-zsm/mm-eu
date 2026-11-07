#include "types.h"
#include "m2c_compat.h"
void func_80181A3C(s16 a, s32 b);
void func_80182C08(f32 a, u8 *b);

void func_80000DF4(s32 a, s32 limb, u8 *c) {
    if (limb == 5) {
        func_80181A3C(0x400 - M2C_FIELD(c, s16 *, 0x2B4), 1);
        func_80182C08(500.0f, c + 0x3C);
    }
}
