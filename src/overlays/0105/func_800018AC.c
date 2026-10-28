// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_808C5B2C(u8 *);                      /* extern */

void func_800018AC(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x2EE) = (s16) (M2C_FIELD(arg0, s16 *, 0x2EE) + 1);
    if (M2C_FIELD(arg0, f32 *, 0x15C) > 20.0f) {
        M2C_FIELD(arg0, s8 *, 0x18C) = 0;
        M2C_FIELD(arg0, u8 *, 0x798) = (u8) (M2C_FIELD(arg0, u8 *, 0x798) & 0xFFFE);
        func_800FEC70(arg0 + 0xBC, 0, 0x200, arg0);
    }
    if (func_80137070(arg0 + 0x144) != 0) {
        M2C_FIELD(arg0, s16 *, 0xBC) = 0;
        func_808C5B2C(arg0);
    }
}
