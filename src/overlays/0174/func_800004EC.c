#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                             /* extern */
M2C_UNK func_800B8284(u8 *, s32, M2C_UNK, M2C_UNK, s32); /* extern */

s32 func_800004EC(u8 *arg0, s32 arg1, u16 arg2) {
    if (func_800B8254(arg0, arg1) != 0) {
        return 1;
    }
    M2C_FIELD(arg0, u16 *, 0x116) = arg2;
    if (M2C_FIELD(arg0, f32 *, 0x98) < 120.0f) {
        func_800B8284(arg0, arg1, 0x43AF0000, 0x447A0000, 0);
    }
    return 0;
}
