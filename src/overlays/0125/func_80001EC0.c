// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(u8 *, s16, M2C_UNK);            /* extern */
M2C_UNK func_801377D0(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_808E62E8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_808E65D8(u8 *);                      /* extern */
extern M2C_UNK D_60010F4;

void func_80001EC0(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, u8 *, 0x2B2) != 0) {
        func_808E65D8(arg0);
        return;
    }
    if ((M2C_FIELD(arg0, s16 *, 0x2BA) == 0) && (func_800FEC70(arg0 + 0x2D0, M2C_FIELD(arg0, s16 *, 0x92), 0x200) != 0)) {
        func_801377D0(arg0 + 0x144, &D_60010F4);
        func_808E62E8(arg0, 0x395B);
        M2C_FIELD(arg0, s16 *, 0x2BA) = 1;
    }
}
