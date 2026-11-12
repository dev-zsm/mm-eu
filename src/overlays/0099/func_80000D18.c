#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_808BD640(u8 *);                      /* extern */

void func_80000D18(u8 *arg0, M2C_UNK arg1) {
    if (func_80137070(arg0 + 0x144) != 0) {
        M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
        M2C_FIELD(arg0, s8 *, 0x18D) = 3;
        func_808BD640(arg0);
    }
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 2, 0xE38);
}
