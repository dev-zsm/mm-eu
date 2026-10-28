// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808AF8E8();                            /* extern */
M2C_UNK func_808AFA38(u8 *);                      /* extern */

void func_8000099C(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x236);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x236) = (s16) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x23C) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_808AF8E8();
    if (M2C_FIELD(arg0, s16 *, 0xBE) == M2C_FIELD(arg0, s16 *, 0x23C)) {
        func_800B8C4C(arg0, 0x3848);
        func_808AFA38(arg0);
    }
}
