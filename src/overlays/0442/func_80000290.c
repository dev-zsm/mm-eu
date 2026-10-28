// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_80102484(s32, s32, s32, s32);          /* extern */

void func_80000290(u8 *arg0, s32 arg1) {
    func_80102484(arg1, arg1 + 0x818, M2C_FIELD(arg0, s32 *, 0x1AC), arg1);
    func_800E09D8(arg1, arg0 + 0x144);
}
