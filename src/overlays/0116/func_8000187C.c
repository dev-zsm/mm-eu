// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80138608(s32, s32 *, s32, M2C_UNK *, M2C_UNK *, s32); /* extern */
extern M2C_UNK D_808DF30C;
extern M2C_UNK D_808DF498;

void func_8000187C(s32 arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_80138608(arg0, arg1, arg0 + 0x14C, &D_808DF30C, &D_808DF498, 1);
}
