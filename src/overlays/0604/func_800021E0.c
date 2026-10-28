// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013C01C(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80BD3BB0;
extern M2C_UNK D_80BD50BC;

void func_800021E0(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x154) == M2C_FIELD(arg0, f32 *, 0x15C)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2D8) = &D_80BD3BB0;
        func_8013C01C(arg0 + 0x144, &D_80BD50BC, 0, arg0);
    }
}
