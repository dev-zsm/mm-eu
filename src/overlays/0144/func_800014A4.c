// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6004A04;
extern M2C_UNK D_8090F904;

void func_800014A4(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_80137828(arg0 + 0x144, &D_6004A04, 0xC0800000, arg0);
    M2C_FIELD(arg0, s16 *, 0x2F6) = 0x18;
    func_800B8C4C(arg0, 0x3AD8);
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090F904;
}
