#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_6017E98;

void func_80000368(u8 *arg0) {
    s32 temp_f10;

    func_80137934(arg0 + 0x144, &D_6017E98, 0xC1200000, arg0);
    M2C_FIELD(arg0, f32 *, 0x2B4) = 0.0f;
    temp_f10 = (s32) (func_8017A844(2.0e+01f) + 40.0f);
    M2C_FIELD(arg0, s16 *, 0x2BC) = (s16) temp_f10;
    M2C_FIELD(arg0, u16 *, 0x2B8) = (u16) (M2C_FIELD(arg0, u16 *, 0x2B8) | 4);
}
