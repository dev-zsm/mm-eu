// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6004C44;
extern M2C_UNK D_8097760C;

void func_8000251C(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) | 1);
    M2C_FIELD(arg0, u8 *, 0x340) = (u8) (M2C_FIELD(arg0, u8 *, 0x340) & 0xFFFE);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 0xA;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_80137788(arg0 + 0x144, &D_6004C44, 0xBF800000, (f32) func_80134AE8(&D_6004C44), 0.0f, 2, -2.0f);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_8097760C;
}
