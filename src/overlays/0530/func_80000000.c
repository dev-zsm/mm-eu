// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800CABA0(s32, M2C_UNK);                /* extern */
M2C_UNK func_800CABC4(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_800FF8DC(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_60019B0;
extern M2C_UNK D_80B7F6E0;

void func_80000000(s32 arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80B7F6E0);
    func_800CABA0(arg0, 1);
    func_800CABC4(arg1, arg0, &D_60019B0);
}
