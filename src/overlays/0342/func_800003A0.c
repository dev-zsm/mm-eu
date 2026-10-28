// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_8013CD14(u8 *, s32, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80A35BA0(u8 *, s32);                 /* extern */
M2C_UNK func_80A35C20(u8 *);                      /* extern */

void func_800003A0(u8 *arg0, s32 arg1) {
    func_80A35BA0(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x144)(arg0, arg1);
    func_80A35C20(arg0);
    func_80137070(arg0 + 0x148);
    func_8013CD14(arg0, arg1, 0x42700000, 0x41F00000, 0, M2C_FIELD(arg0, u16 *, 0x18C) & 7);
    func_800B64E0(arg0, 0x41D00000);
}
