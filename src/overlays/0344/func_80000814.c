#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80A37A58(u8 *, s32);                     /* extern */
extern M2C_UNK D_80A37D18;

s32 func_80000814(u8 *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, u16 *, 0x37C) & 7) {
        var_v1 = 0;
        if (func_800B8254(arg0, arg1) != 0) {
            func_8013B284(arg0 + 0x37C, 0, 7);
            M2C_FIELD(arg0, s32 *, 0x380) = func_80A37A58(arg0, arg1);
            M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80A37D18;
            var_v1 = 1;
        }
    }
    return var_v1;
}
