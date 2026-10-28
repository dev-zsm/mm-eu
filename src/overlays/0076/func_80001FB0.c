// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, s32, f32, s32, f32); /* extern */
extern M2C_UNK D_60025B4;
extern M2C_UNK D_8089B9C8;
extern M2C_UNK D_8089BE44;

void func_80001FB0(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60025B4, 0xBF800000, M2C_FIELD(arg0, s32 *, 0x15C), 0.0f, 2, 0.0f);
    M2C_FIELD(arg0, u8 *, 0x5D4) = (u8) (M2C_FIELD(arg0, u8 *, 0x5D4) & 0xFFFA);
    if (&D_8089B9C8 != M2C_FIELD(arg0, M2C_UNK **, 0x284)) {
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    } else {
        M2C_FIELD(arg0, f32 *, 0x70) = 3.0f;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x284) = &D_8089BE44;
}
