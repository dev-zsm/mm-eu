#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0555.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80BA51FC(u8 *, s32);                     /* extern */
extern M2C_UNK D_80BA5C4C;

s32 func_8000074C(u8 *arg0, s32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (M2C_FIELD(arg0, u16 *, 0x262) & 7) {
        var_v1 = 0;
        if (func_800B8254(arg0, arg1) != 0) {
            M2C_FIELD(arg0, u16 *, 0x262) = (u16) (M2C_FIELD(arg0, u16 *, 0x262) | 0x20);
            func_8013B284(arg0 + 0x262, 0, 7);
            M2C_FIELD(arg0, s16 *, 0x288) = 0;
            M2C_FIELD(arg0, s32 *, 0x28C) = 0;
            M2C_FIELD(arg0, s32 *, 0x124) = (s32) M2C_FIELD(arg0, s32 *, 0x1E8);
            M2C_FIELD(arg0, s32 *, 0x1E0) = func_80BA51FC(arg0, arg1);
            M2C_FIELD(arg0, u16 *, 0x262) = (u16) (M2C_FIELD(arg0, u16 *, 0x262) | 0x20);
            M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BA5C4C;
            var_v1 = 1;
        }
    }
    return var_v1;
}
