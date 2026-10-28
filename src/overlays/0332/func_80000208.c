// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(s32, s32);                    /* extern */
M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_801A3D9C();                            /* extern */

void func_80000208(u8 *arg0, s32 arg1) {
    func_800E0FAC(arg1, arg0 + 0x6F4);
    func_800E09D8(arg1, arg0 + 0x454);
    if (M2C_FIELD(arg0, s16 *, 0x74A) != 2) {
        func_801A3D9C();
    }
}
