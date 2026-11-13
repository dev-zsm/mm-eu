#include "types.h"
#include "m2c_compat.h"

f32 func_800FEB84(s16, u8 *);                     /* extern */
extern f32 D_80B20E18;
extern f32 D_80B20E1C;

void func_80000C54(u8 *arg0) {
    f32 var_f2;
    f32 sp1C;
    f32 temp_f10;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2EE);
    if ((temp_v0 != 5) && (temp_v0 != 7)) {
        M2C_FIELD(arg0, s16 *, 0x2F2) = (s16) (M2C_FIELD(arg0, s16 *, 0x2F2) + 0x62C);
        var_f2 = D_80B20E18;
    } else {
        M2C_FIELD(arg0, s16 *, 0x2F2) = (s16) (M2C_FIELD(arg0, s16 *, 0x2F2) + 0x7BC);
        var_f2 = D_80B20E1C;
    }
    sp1C = var_f2;
    M2C_FIELD(arg0, f32 *, 0xC4) = (f32) (func_800FEB84(M2C_FIELD(arg0, s16 *, 0x2F2), arg0) * var_f2);
    temp_f10 = func_800FEB84(M2C_FIELD(arg0, s16 *, 0x2F2), arg0) * 5.0f;
    M2C_FIELD(arg0, s16 *, 0x2F6) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) - M2C_FIELD(arg0, s16 *, 0xBE));
    M2C_FIELD(arg0, f32 *, 0xCC) = (f32) (30.0f - temp_f10);
}
