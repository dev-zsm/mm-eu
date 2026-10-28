// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK, u8 *); /* extern */
M2C_UNK func_808E9924(u8 *);                      /* extern */

void func_800057D4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, f32 *, 0x15C) > 10.0f) {
        func_800FEC70(arg0 + 0x2D0, M2C_FIELD(arg0, s16 *, 0x2B6), 0x800, arg0);
    }
    if (M2C_FIELD(arg0, u8 *, 0x2B2) != 0) {
        func_808E9924(arg0);
    }
}
