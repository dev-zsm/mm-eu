#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */

void func_8000272C(u8 *arg0) {
    f32 temp_f0;
    s32 temp_f8;

    temp_f0 = func_8008704C();
    temp_f8 = (s32) (temp_f0 * 30.0f);
    M2C_FIELD(arg0, s8 *, 0x294) = (s8) (temp_f8 + 0xE1);
    M2C_FIELD(arg0, s8 *, 0x297) = (s8) (temp_f8 + 0xDC);
    M2C_FIELD(arg0, s8 *, 0x295) = (s8) ((s32) (temp_f0 * 100.0f) + 0x9B);
    M2C_FIELD(arg0, s8 *, 0x296) = (s8) ((s32) (temp_f0 * 160.0f) + 0x5F);
    M2C_FIELD(arg0, s8 *, 0x297) = (s8) (temp_f8 + 0xDC);
}
