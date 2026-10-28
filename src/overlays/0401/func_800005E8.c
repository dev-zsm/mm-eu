// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDD44(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_60001E0;

void func_800005E8(s32 arg0, M2C_UNK arg1) {
    func_800BDD44(arg1, &D_60001E0, arg1);
}
