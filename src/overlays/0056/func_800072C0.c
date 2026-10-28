// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8082D240(s32, s32, s32);               /* extern */
M2C_UNK func_80830B44(s32, s32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80834380(s32, s32, u16);               /* extern */
extern M2C_UNK D_8084B860;

void func_800072C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    func_80830B44(arg0, arg1, &D_8084B860, 1);
    if (arg2 != 0) {
        func_8082D240(arg0, arg1, arg2);
    }
    func_80834380(arg1, arg3, arg4);
}
