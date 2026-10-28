// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80B2AA10(u8 *);                      /* extern */

void func_80004D8C(u8 *arg0) {
    u8 *sp20;
    s16 temp_v0;
    u8 *temp_a0;

    if (M2C_FIELD(arg0, s32 *, 0x120) == 0) {
        func_800B6490(arg0);
        return;
    }
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *), 0x2EC)(arg0);
    func_80137070(arg0 + 0x144);
    temp_a0 = arg0 + 0x324;
    sp20 = temp_a0;
    func_80B2AA10(temp_a0);
    temp_v0 = M2C_FIELD(temp_a0, s16 *, 0x40);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0xBC) = (s16) -temp_v0;
    }
}
