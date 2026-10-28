// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B7164(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80869DD0(u8 *, s32);                 /* extern */
M2C_UNK func_8086C06C(u8 *);                      /* extern */

void func_80002A8C(u8 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;

    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x1000, 0x80);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x32);
    func_80137070(arg0 + 0x144);
    func_80869DD0(arg0, arg1);
    if (!(M2C_FIELD(arg0, u16 *, 0x90) & 1) || ((temp_f0 = M2C_FIELD(arg0, f32 *, 0x15C), (temp_f0 > 1.0f)) && (temp_f0 < 12.0f))) {
        M2C_FIELD(arg0, f32 *, 0x70) = 8.0f;
    } else {
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    if ((M2C_FIELD(arg0, u8 *, 0x396) & 2) && (M2C_FIELD(arg0, u8 *, 0x397) & 1) && (func_800B7164(arg0, 0x3000) != 0) && ((temp_f0_2 = M2C_FIELD(arg0, f32 *, 0x15C), (temp_f0_2 <= 2.0f)) || (temp_f0_2 >= 11.0f))) {
        func_8086C06C(arg0);
    }
}
