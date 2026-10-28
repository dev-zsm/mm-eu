// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
s32 func_80137C58(u8 *, s32);                     /* extern */
M2C_UNK func_80BBE16C(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BBF258;

void func_80001F18(u8 *arg0, M2C_UNK arg1) {
    u8 *temp_s0;

    temp_s0 = arg0 + 0x190;
    if (M2C_FIELD(arg0, s16 *, 0x31E) == 1) {
        if ((func_80137C58(temp_s0, 0x40000000) != 0) || (func_80137C58(temp_s0, 0x40C00000) != 0) || (func_80137C58(temp_s0, 0x41200000) != 0) || (func_80137C58(temp_s0, 0x41600000) != 0)) {
            func_800B8C4C(arg0, 0x298B);
        }
        if (func_80137C58(temp_s0, M2C_FIELD(arg0, s32 *, 0x1A0)) != 0) {
            M2C_FIELD(arg0, s16 *, 0x31E) = 0;
            func_80BBE16C(arg0, 0, 0);
            func_800BD9E0(temp_s0, &D_80BBF258, 0xA);
        }
    }
}
