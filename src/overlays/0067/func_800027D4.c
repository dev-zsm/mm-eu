#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018142C(f32, f32, s32, M2C_UNK);      /* extern */

s32 func_800027D4(s32 arg0, s32 arg1, M2C_UNK arg2, u8 *arg3, s32 arg4, u8 *arg5) {
    if (arg1 == 1) {
        M2C_FIELD(arg3, f32 *, 8) = (f32) (M2C_FIELD(arg3, f32 *, 8) + 1000.0f);
    } else if ((arg1 == 0xF) || (arg1 == 0x10)) {
        func_8018142C(M2C_FIELD(arg5, f32 *, 0x314), M2C_FIELD(arg5, f32 *, 0x318), M2C_FIELD(arg5, s32 *, 0x31C), 1);
    }
    return 0;
}
