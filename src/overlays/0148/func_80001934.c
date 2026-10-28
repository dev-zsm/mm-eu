// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
f32 func_800FEB84(s16);                             /* extern */

void func_80001934(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x220);
    if (temp_v0 > 0) {
        M2C_FIELD(arg0, s16 *, 0x220) = (s16) (temp_v0 - 1);
    }
    M2C_FIELD(arg0, s8 *, 0x2C0) = 0;
    M2C_FIELD(arg0, s16 *, 0x238) = (s16) (M2C_FIELD(arg0, s16 *, 0x238) + 0x640);
    if (M2C_FIELD(arg0, s16 *, 0x1C) != 4) {
        M2C_FIELD(arg0, f32 *, 0xC4) = (f32) ((func_800FEB84(M2C_FIELD(arg0, s16 *, 0x238)) * 1000.0f) + 600.0f);
    }
    func_800B64E0(arg0, 0x40A00000);
    func_800B8C4C(arg0, 0x205B);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x144)(arg0, arg1);
    M2C_FIELD(arg0, s16 *, 0x23A) = (s16) (M2C_FIELD(arg0, s16 *, 0x23A) - 0x14);
    M2C_FIELD(arg0, s16 *, 0x23A) = (s16) (M2C_FIELD(arg0, s16 *, 0x23A) & 0x1FF);
}
