// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8013C01C(u8 *, M2C_UNK *, s32, u8 *);  /* extern */
extern M2C_UNK D_80C02B80;

s32 func_80000000(u8 *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (arg1 != M2C_FIELD(arg0, s32 *, 0x294)) {
        M2C_FIELD(arg0, s32 *, 0x294) = arg1;
        var_v1 = func_8013C01C(arg0 + 0x144, &D_80C02B80, arg1, arg0);
    }
    return var_v1;
}
