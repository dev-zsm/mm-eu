// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, u8, M2C_UNK);            /* extern */
M2C_UNK func_800FFAD8(u8 *, f32, M2C_UNK, M2C_UNK, f32); /* extern */
extern f32 D_808B7A34;
extern f32 D_808B7A38;

void func_800004CC(u8 *arg0, M2C_UNK arg1) {
    f32 var_f0;

    if (func_800B5B20(arg1, M2C_FIELD(arg0, u8 *, 0x15D), arg1) != 0) {
        var_f0 = 1.0f;
    } else {
        var_f0 = D_808B7A34;
    }
    func_800FFAD8(arg0 + 0x58, var_f0, 0x3E4CCCCD, 0x3E99999A, D_808B7A38);
}
