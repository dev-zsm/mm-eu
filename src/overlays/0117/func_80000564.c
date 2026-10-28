// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDDC0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_5000C40;

void func_80000564(s32 arg0, M2C_UNK arg1) {
    func_800BDDC0(arg1, &D_5000C40, arg1);
}
