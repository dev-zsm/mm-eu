// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BDD44(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6000390;
extern M2C_UNK D_6000438;

void func_800005E0(s32 arg0, s32 arg1) {
    func_800BDD44(arg1, &D_6000438);
    func_800BDD44(arg1, &D_6000390);
}
