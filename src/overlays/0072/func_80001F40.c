// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, s32, u8 *); /* extern */
M2C_UNK func_808929D0(u8 *, s32 *);               /* extern */
extern M2C_UNK D_80892590;

void func_80001F40(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), M2C_FIELD(arg0, u8 *, 0x146), &D_80892590, 0, arg0);
    func_808929D0(arg0, arg1);
}
