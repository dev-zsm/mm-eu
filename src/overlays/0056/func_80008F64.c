// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_801238D0(s32);                             /* extern */
s32 func_801238E4(s32);                             /* extern */
M2C_UNK func_80830B44(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_80849190;
extern M2C_UNK D_808494C4;
extern M2C_UNK D_808496D4;

void func_80008F64(s32 arg0, s32 arg1) {
    M2C_UNK *var_a2;

    if (func_801238D0(arg0) != 0) {
        var_a2 = &D_80849190;
    } else if (func_801238E4(arg0) != 0) {
        var_a2 = &D_808494C4;
    } else {
        var_a2 = &D_808496D4;
    }
    func_80830B44(arg1, arg0, var_a2, 1);
}
