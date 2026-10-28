// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FD394(s32, u8 *, s32);            /* extern */
M2C_UNK func_800FD3D8(s32, u8 *, s32);            /* extern */
M2C_UNK func_800FD44C(s32, u8 *, s32);            /* extern */
M2C_UNK func_800FD490(s32, s16, s16, s32);          /* extern */

void func_8000159C(s32 arg0, u8 *arg1, s32 arg2) {
    func_800FD394(arg0, arg1, arg2);
    func_800FD3D8(arg0, arg1 + 3, arg2);
    func_800FD44C(arg0, arg1 + 6, arg2);
    func_800FD490(arg0, M2C_FIELD(arg1, s16 *, 0xA), M2C_FIELD(arg1, s16 *, 0xC), arg2);
}
