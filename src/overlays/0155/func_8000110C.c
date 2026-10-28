// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_80920824(u8 *);                      /* extern */
M2C_UNK func_80920900(u8 *);                      /* extern */

void func_8000110C(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 8) & 0x7F, arg0, arg1) != 0) {
        func_80920900(arg0);
        return;
    }
    func_80920824(arg0);
}
