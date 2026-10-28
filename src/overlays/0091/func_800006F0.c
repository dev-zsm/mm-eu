// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

f32 func_800B6BCC(u8 *, u8 *);                  /* extern */
M2C_UNK func_808AF8E8();                            /* extern */
M2C_UNK func_808AFB40(u8 *);                      /* extern */
M2C_UNK func_808AFD20(u8 *);                      /* extern */

void func_800006F0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x23C) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    func_808AF8E8();
    if (M2C_FIELD(arg0, u16 *, 0x90) & 2) {
        M2C_FIELD(arg0, s16 *, 0x236) = (s16) (M2C_FIELD(arg0, s16 *, 0x236) - 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x236) == 0) {
        func_808AFD20(arg0);
        return;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x238) == 0) || (func_800B6BCC(arg0, arg0 + 8) > 240.0f)) {
        func_808AFB40(arg0);
    }
}
