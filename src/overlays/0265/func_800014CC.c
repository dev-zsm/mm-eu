// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80993B84(u8 *);                      /* extern */

void func_800014CC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;

    M2C_FIELD(arg0, s16 *, 0x30) = (s16) (M2C_FIELD(arg0, s16 *, 0x30) + 0x1770);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0xA, 0xFA0, 0x14);
    if (!(M2C_FIELD(arg0, f32 *, 0x68) > 0.0f) && (M2C_FIELD(arg0, u16 *, 0x90) & 1)) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x92);
        M2C_FIELD(arg0, s16 *, 0x30) = 0;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, s16 *, 0xBE) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
        func_80993B84(arg0);
    }
}
