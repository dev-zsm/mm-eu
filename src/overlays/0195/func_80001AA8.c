// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80958C30(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80958C3C(u8 *, s32);                 /* extern */
M2C_UNK func_809590B4(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80959208(u8 *);                      /* extern */
M2C_UNK func_8095923C(u8 *);                      /* extern */
s32 func_80959764(u8 *, s32);                     /* extern */
s32 func_80959884(u8 *);                          /* extern */
extern M2C_UNK D_8095A7D8;
extern M2C_UNK func_8095A5F0;

void func_80001AA8(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_v1;
    s16 var_v1_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x520);
    if (temp_v0 != 0) {
        if (temp_v0 == 0) {
            var_v1 = 0;
        } else {
            M2C_FIELD(arg0, s16 *, 0x520) = (s16) (temp_v0 - 1);
            var_v1 = M2C_FIELD(arg0, s16 *, 0x520);
        }
        if (var_v1 == 0) {
            func_809590B4(arg0, 4);
        }
    }
    if (func_80959764(arg0, arg1) == 0) {
        func_80959208(arg0);
        func_80958C30(arg0, &D_8095A7D8);
        return;
    }
    if (func_80959884(arg0) != 0) {
        func_80958C3C(arg0, arg1);
        func_8095923C(arg0);
        func_80958C30(arg0, &func_8095A5F0);
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x528);
    if (temp_v0_2 == 0) {
        var_v1_2 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x528) = (s16) (temp_v0_2 - 1);
        var_v1_2 = M2C_FIELD(arg0, s16 *, 0x528);
    }
    if (var_v1_2 == 0) {
        func_800B8C4C(arg0, 0x3868);
        M2C_FIELD(arg0, s16 *, 0x528) = 3;
    }
}
