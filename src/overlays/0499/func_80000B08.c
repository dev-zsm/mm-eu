// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80147CC4(s32);                         /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_80B4C5D8;

void func_80000B08(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x190);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2A0) = &D_80B4C5D8;
        func_80147CC4(arg1);
    }
    M2C_FIELD(arg0, s16 *, 0x294) = -0x1388;
}
