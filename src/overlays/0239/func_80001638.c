#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_6005700;
extern M2C_UNK D_80976734;

void func_80001638(u8 *arg0) {
    s32 temp_f8;

    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) | 1);
    func_80137934(arg0 + 0x144, &D_6005700, 0xC0800000);
    if (func_8008704C() > 0.5f) {
        M2C_FIELD(arg0, s16 *, 0x29A) = 0x3E80;
    } else {
        M2C_FIELD(arg0, s16 *, 0x29A) = -0x3E80;
    }
    M2C_FIELD(arg0, f32 *, 0x70) = 6.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    temp_f8 = (s32) func_8017A844(3.0e+01f);
    M2C_FIELD(arg0, s16 *, 0x2A0) = (s16) (temp_f8 + 0x1E);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80976734;
}
