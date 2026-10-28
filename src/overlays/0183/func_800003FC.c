// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_8094C924;

void func_800003FC(u8 *arg0, u8 *arg1) {
    func_80137070(arg0 + 0x1DC);
    if ((func_801529DC(arg1 + 0x4908) == 2) && (M2C_FIELD(arg1, u16 *, 0x16810) == 0x6DE)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2FC) = &D_8094C924;
    }
}
