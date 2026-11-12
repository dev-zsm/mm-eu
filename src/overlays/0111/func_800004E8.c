#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_801378E0(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_60081A8;
extern M2C_UNK D_600ABE0;
extern M2C_UNK D_808D3A7C;

void func_800004E8(u8 *arg0) {
    f32 temp_f6;

    if (M2C_FIELD(arg0, s16 *, 0x1C) != 2) {
        func_80137934(arg0 + 0x144, &D_600ABE0, 0xC0C00000);
    } else {
        func_801378E0(arg0 + 0x144, &D_60081A8);
    }
    M2C_FIELD(arg0, s8 *, 0x3EF) = 0;
    temp_f6 = func_8008704C() * 10.0f;
    M2C_FIELD(arg0, s16 *, 0x3D6) = (s16) (s32) (temp_f6 + 5.0f);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D3A7C;
}
