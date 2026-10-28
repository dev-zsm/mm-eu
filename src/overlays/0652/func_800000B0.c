// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80C04288(s32);                         /* extern */
M2C_UNK func_80C042FC(s32, s32);                    /* extern */

void func_800000B0(s32 arg0, M2C_UNK arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = arg0 + 0x148;
    do {
        func_80C042FC(arg0, var_s1);
        var_s0 += 0x34;
        var_s1 += 0x34;
    } while (var_s0 != 0xC30);
    func_80C04288(arg0);
}
