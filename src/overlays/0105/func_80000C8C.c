#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, f32, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_600B284;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_808C5384;
extern f32 D_808C9258;

void func_80000C8C(u8 *arg0) {
    M2C_FIELD(&D_801E6EF0, u8 *, 0x1012) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0x1012) | 8);
    func_80137788(arg0 + 0x144, &D_600B284, 0.0f, 0.0f, (f32) func_80134AE8(&D_600B284), 2, 0.0f);
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) D_808C9258;
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x777F);
    func_800B8C4C(arg0, 0x3AB4);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808C5384;
}
