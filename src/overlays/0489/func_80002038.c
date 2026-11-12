#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(s16, s16, u8 *, u8 *);        /* extern */

void func_80002038(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s8 *, 4) = (s8) M2C_FIELD(arg1, s8 *, 0);
    M2C_FIELD(arg0, u8 **, 8) = arg1;
    M2C_FIELD(arg0, s8 *, 0xE) = 0;
    M2C_FIELD(arg0, s8 *, 0xF) = (s8) **M2C_FIELD(arg1, s8 ***, 4);
    if (M2C_FIELD(arg0, s8 *, 4) == 2) {
        M2C_FIELD(arg0, s16 *, 0xC) = func_800FF250(M2C_FIELD(arg1, s16 *, 0x10), M2C_FIELD(arg1, s16 *, 0x12), arg0, arg1);
    }
}
