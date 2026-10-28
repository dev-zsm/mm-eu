// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6004A90;
extern M2C_UNK D_80976FF4;

void func_80001F2C(u8 *arg0) {
    s16 temp_v0;

    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) & 0xFFFE);
    func_80137828(arg0 + 0x144, &D_6004A90, 0xC0400000, arg0);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = -6.0f;
    M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    func_800B8C4C(arg0, 0x386C);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80976FF4;
}
