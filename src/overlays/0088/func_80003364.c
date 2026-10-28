// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800F1E68(s16);                             /* extern */

void func_80003364(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x2B8) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
    M2C_FIELD(arg0, s16 *, 0x2BA) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x2B8));
    M2C_FIELD(arg0, s16 *, 0x2BC) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x2BA));
    M2C_FIELD(arg0, s16 *, 0x2BE) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x2BC));
}
