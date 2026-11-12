#include "types.h"
#include "m2c_compat.h"

s32 func_80136480(s32, s32);                        /* extern */
M2C_UNK func_8083F3E4(s32, u8 *, f32, M2C_UNK, f32); /* extern */
M2C_UNK func_80840A4C(s32, u8 *, M2C_UNK);        /* extern */

void func_8002C500(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    if (func_80136480(arg0, arg1 + 0x240) != 0) {
        func_8083F3E4(arg0, arg1, 0, 0x42C60000, M2C_FIELD(arg1, f32 *, 0x250) - 8.0f);
    }
    if (M2C_FIELD(arg1, s8 *, 0x147) != 5) {
        func_80840A4C(arg0, arg1, 1);
    }
}
