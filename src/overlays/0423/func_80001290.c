#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s16 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60008B4;
extern M2C_UNK D_80ABCE3C;

void func_80001290(u8 *arg0) {
    s16 sp36;
    s16 temp_v0;

    temp_v0 = func_80134AE8(&D_60008B4);
    sp36 = temp_v0;
    func_80137788(arg0 + 0x144, &D_60008B4, 0x3F800000, 0, (f32) temp_v0, 2, -3.0f);
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, (s32) sp36);
    func_800B8C4C(arg0, 0x38F9);
    M2C_FIELD(arg0, u8 *, 0x351) = (u8) (M2C_FIELD(arg0, u8 *, 0x351) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80ABCE3C;
}
