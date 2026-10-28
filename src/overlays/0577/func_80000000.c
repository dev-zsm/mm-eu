// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800CABA0(s32, M2C_UNK);                /* extern */
M2C_UNK func_800CABC4(s32, s32, M2C_UNK *);         /* extern */
M2C_UNK func_800FF8DC(s32, M2C_UNK *);              /* extern */
M2C_UNK func_8013E768(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_80BBB3C4(s32);                         /* extern */
extern M2C_UNK D_6000EE8;
extern M2C_UNK D_80BBB640;

void func_80000000(s32 arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80BBB640);
    func_800CABA0(arg0, 1);
    func_800CABC4(arg1, arg0, &D_6000EE8);
    func_8013E768(arg0, arg0 + 0x160, 1);
    func_80BBB3C4(arg0);
}
