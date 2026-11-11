#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0257.h"

s16 func_800B6A58();                                /* extern */

void func_800000D0(s32 arg0, u8 *arg1) {
    M2C_FIELD(arg1, f32 *, 0x2F0) = 30.0f;
    M2C_FIELD(arg1, s16 *, 0x2F4) = func_800B6A58(arg0, arg1);
}
