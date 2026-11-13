#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0437.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80AD31A8(u8 *, s32);                 /* extern */

void func_80001FB4(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x2CC), 2, 0xE38, 0x5B);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, s16 *, 0x32) = temp_v0;
    if ((M2C_FIELD(arg0, s16 *, 0x2CC) - temp_v0) == 0) {
        func_80AD31A8(arg0, arg1);
    }
}
