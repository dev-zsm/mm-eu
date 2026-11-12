#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s8 func_800FF250(M2C_UNK, M2C_UNK);                 /* extern */
M2C_UNK func_808338A4(s32, u8 *);                 /* extern */

void func_80006A30(s32 arg0, u8 *arg1) {
    s32 var_s0;
    u8 *var_s1;

    var_s0 = 0;
    var_s1 = arg1;
    do {
        M2C_FIELD(var_s1, s8 *, 0xD45) = func_800FF250(0, 0xC8);
        var_s0 += 1;
        var_s1 += 1;
    } while (var_s0 != 0x12);
    M2C_FIELD(arg1, s8 *, 0xD44) = 1;
    func_808338A4(arg0, arg1);
}
