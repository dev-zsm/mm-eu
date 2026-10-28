// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FED2C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_808D0CEC(u8 *);                      /* extern */

void func_80000DD8(u8 *arg0, M2C_UNK arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        func_808D0CEC(arg0);
    }
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (M2C_FIELD(arg0, s16 *, 0xBC) + 0x140);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x28) + 10.0f);
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 3, 0xAAA);
    func_800FED2C(arg0 + 0x192, 0x4B0, 0x64);
}
