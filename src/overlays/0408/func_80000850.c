// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
M2C_UNK func_800BDDC0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6001DB0;
extern M2C_UNK D_6001E40;

void func_80000850(s32 arg0, s32 arg1) {
    func_800BDD44(arg1, &D_6001E40);
    func_800BDDC0(arg1, &D_6001DB0);
}
