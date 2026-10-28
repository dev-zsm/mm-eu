// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF8DC(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80A739BC(s32, s32);                    /* extern */
extern M2C_UNK D_80A74B78;

void func_8000403C(s32 arg0, s32 arg1) {
    func_800FF8DC(arg0, &D_80A74B78);
    func_80A739BC(arg0, arg1);
}
