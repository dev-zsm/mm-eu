#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_801A3D04(M2C_UNK);                     /* extern */
M2C_UNK func_80B47224(u8 *);                      /* extern */

void func_80000DDC(u8 *arg0, M2C_UNK arg1) {
    s16 var_v0;

    M2C_FIELD(arg0, s16 *, 0x206) = (s16) (M2C_FIELD(arg0, s16 *, 0x206) + 1);
    var_v0 = M2C_FIELD(arg0, s16 *, 0x206);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) - M2C_FIELD(arg0, s16 *, 0x20A));
    if (var_v0 >= 0x10) {
        func_800FEC70(arg0 + 0x20A, 0, 0x200, arg0);
        var_v0 = M2C_FIELD(arg0, s16 *, 0x206);
    }
    M2C_FIELD(arg0, s8 *, 0x293) = (s8) (u32) ((f32) var_v0 * 7.96875f);
    if (var_v0 == 0x20) {
        M2C_FIELD(arg0, u8 *, 0x293) = 0xFF;
        if (M2C_FIELD(arg0, u8 *, 0x204) == 0) {
            func_801A3D04(0x38);
            M2C_FIELD(arg0, u8 *, 0x204) = 1U;
        }
        func_80B47224(arg0);
    }
}
