// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, s32, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80956A20;

void func_80002740(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x150), M2C_FIELD(arg0, s32 *, 0x16C), M2C_FIELD(arg0, u8 *, 0x14E), 0, &D_80956A20, arg0);
}
