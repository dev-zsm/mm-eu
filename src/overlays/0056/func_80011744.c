#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s32 func_808325D4();                                /* extern */
void func_8083E838();                     /* extern */

s32 func_80011744(u8 *arg0, f32 *arg1, s16 *arg2, M2C_UNK arg3) {
    if (M2C_FIELD(arg0, f32 *, 0xAD0) > 6.0f) {
        func_8083E838(arg0, arg3);
        return 1;
    }
    if (*arg1 != 0.0f) {
        if (func_808325D4() != 0) {
            *arg1 = 0.0f;
            *arg2 = M2C_FIELD(arg0, s16 *, 0xAD4);
            goto block_6;
        }
        return 1;
    }
block_6:
    return 0;
}
