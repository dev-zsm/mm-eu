// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_808E3814(u8 *);                      /* extern */

void func_80000568(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0xA, 0x7D0, 0);
    temp_f0 = M2C_FIELD(arg0, f32 *, 0x98);
    if ((temp_f0 <= 240.0f) && (temp_f0 > 0.0f)) {
        func_808E3814(arg0);
    }
}
