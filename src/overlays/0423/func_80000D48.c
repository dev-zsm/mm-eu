#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60031DC;
extern M2C_UNK D_80ABC8C0;
extern M2C_UNK D_80ABD8F0;
extern f32 D_80ABDC28;

void func_80000D48(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80ABD8F0;
    func_80137828(arg0 + 0x144, &D_60031DC, 0xC0400000, arg0);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x2AC) = (f32) D_80ABDC28;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80ABC8C0;
    M2C_FIELD(arg0, f32 *, 0x2A8) = 1.0f;
}
