#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80968AFC();                            /* extern */
M2C_UNK func_8096944C(u8 *);                      /* extern */
extern f32 D_8096A5B0;

void func_80000B60(u8 *arg0) {
    s16 var_v0;
    s32 temp_v1;

    M2C_FIELD(arg0, s16 *, 0x14A) = (s16) (M2C_FIELD(arg0, s16 *, 0x14A) - 1);
    var_v0 = M2C_FIELD(arg0, s16 *, 0x14A);
    if ((var_v0 % 25) == 0) {
        func_80968AFC();
        var_v0 = M2C_FIELD(arg0, s16 *, 0x14A);
    }
    temp_v1 = var_v0 * 0xA;
    M2C_FIELD(arg0, f32 *, 0x150) = (f32) ((f32) var_v0 * D_8096A5B0);
    if (temp_v1 >= 0xC9) {
        M2C_FIELD(arg0, u8 *, 0x148) = -0x38;
    } else {
        M2C_FIELD(arg0, s8 *, 0x148) = temp_v1;
    }
    func_800B8D94(arg0, 0x2144);
    if (M2C_FIELD(arg0, s16 *, 0x14A) == 0) {
        func_8096944C(arg0);
    }
}
