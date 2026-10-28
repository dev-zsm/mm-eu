// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800F1E68(s16);                             /* extern */

void func_80003168(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x36C) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
    M2C_FIELD(arg0, s16 *, 0x36E) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x36C));
    M2C_FIELD(arg0, s16 *, 0x370) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x36E));
    M2C_FIELD(arg0, s16 *, 0x372) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x370));
}
