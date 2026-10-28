// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800F1E68(s16, u8 *);                     /* extern */

void func_80002A74(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x3A2) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
    M2C_FIELD(arg0, s16 *, 0x3A4) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x3A2), arg0);
    M2C_FIELD(arg0, s16 *, 0x3A6) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x3A4), arg0);
}
