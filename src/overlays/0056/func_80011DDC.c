#include "types.h"
#include "m2c_compat.h"

f32 func_8017A870(f32);                             /* extern */

void func_80011DDC(u8 *arg0, u8 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    M2C_FIELD(arg1, f32 *, 0) = (f32) (M2C_FIELD(arg0, f32 *, 0) + func_8017A870(arg3));
    M2C_FIELD(arg1, f32 *, 4) = (f32) ((M2C_FIELD(arg0, f32 *, 4) + arg2) + func_8017A870(arg4));
    M2C_FIELD(arg1, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + func_8017A870(arg3));
}
