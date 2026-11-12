#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_80000000(u8 *arg0) {
    s32 var_v0;
    s16 var_v1;

    var_v1 = M2C_FIELD(arg0, s16 *, 0x2FA);
    if (var_v1 == 0) {
        var_v0 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x2FA) = (s16) (var_v1 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x2FA);
        var_v0 = var_v1;
    }
    if (var_v0 == 0) {
        M2C_FIELD(arg0, s16 *, 0x2FA) = func_800FF250(0x3C, 0x3C, arg0);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x2FA);
    }
    M2C_FIELD(arg0, s16 *, 0x2F8) = var_v1;
    if (M2C_FIELD(arg0, s16 *, 0x2F8) >= 3) {
        M2C_FIELD(arg0, s16 *, 0x2F8) = 0;
    }
}
