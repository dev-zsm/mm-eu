// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(s32, s16, M2C_UNK, M2C_UNK);  /* extern */
s32 func_801244EC(s32);                             /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_808BD37C(u8 *);                      /* extern */

void func_800014E4(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (func_801244EC(arg1) != 0x10) {
        func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 2, 0xE38);
    }
    if (M2C_FIELD(arg0, f32 *, 0x98) > 480.0f) {
        func_808BD37C(arg0);
    }
}
