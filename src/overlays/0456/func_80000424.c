// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800F1E68(s16, u8 *);                     /* extern */

void func_80000424(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x282) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
    M2C_FIELD(arg0, s16 *, 0x284) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x282), arg0);
    M2C_FIELD(arg0, s16 *, 0x286) = func_800F1E68(M2C_FIELD(arg0, s16 *, 0x284), arg0);
}
