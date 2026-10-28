// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_80AB0670();                            /* extern */

void func_800006A8(u8 *arg0) {
    u8 temp_v0;
    u8 temp_v0_2;

    if (((M2C_FIELD(arg0, s16 *, 0x1C) & 1) == 1) && ((s32) M2C_FIELD(arg0, u8 *, 0x196) >= 0x5B)) {
        func_80AB0670();
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x196);
    if ((s32) temp_v0 >= 6) {
        M2C_FIELD(arg0, u8 *, 0x196) = (u8) (temp_v0 - 5);
    } else {
        M2C_FIELD(arg0, u8 *, 0x196) = 0U;
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 0xD0);
    if ((s32) temp_v0_2 >= 3) {
        M2C_FIELD(arg0, u8 *, 0xD0) = (u8) (temp_v0_2 - 2);
        return;
    }
    func_800B6490(arg0);
}
