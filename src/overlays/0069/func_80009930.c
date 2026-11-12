#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0069.h"

f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */

void func_80009930(u8 *arg0, s16 arg1, f32 arg2, f32 arg3, u8 *arg4) {
    M2C_FIELD(arg4, f32 *, 0) = (f32) (M2C_FIELD(arg0, f32 *, 0) + (func_800FEB84(arg1) * arg2));
    M2C_FIELD(arg4, f32 *, 4) = (f32) (M2C_FIELD(arg0, f32 *, 4) + arg3);
    M2C_FIELD(arg4, f32 *, 8) = (f32) (M2C_FIELD(arg0, f32 *, 8) + (func_800FEB44(arg1) * arg2));
}
