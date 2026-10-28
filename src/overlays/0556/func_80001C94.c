// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BA8160(s32, M2C_UNK);                /* extern */

void func_80001C94(s32 arg0, M2C_UNK arg1) {
    s32 var_s0;
    s32 var_s1;

    var_s0 = arg0 + 0x234;
    var_s1 = 0;
    do {
        func_80BA8160(var_s0, arg1);
        var_s1 += 1;
        var_s0 += 0x10;
    } while (var_s1 != 4);
}
