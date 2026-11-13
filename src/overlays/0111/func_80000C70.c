#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60118D8;
extern M2C_UNK D_808D41F0;

void func_80000C70(u8 *arg0) {
    f32 temp_f10;

    func_80137934(arg0 + 0x144, &D_60118D8, 0xC0C00000, arg0);
    M2C_FIELD(arg0, s8 *, 0x3EF) = 0x10;
    temp_f10 = (func_8008704C() * 10.0f) + 5.0f;
    M2C_FIELD(arg0, s16 *, 0x3D6) = (s16) (s32) temp_f10;
    M2C_FIELD(arg0, s16 *, 0x3E4) = 0x1112;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D41F0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
