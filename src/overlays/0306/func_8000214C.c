// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_80A0DFD8(u8 *, s32 *);               /* extern */
extern M2C_UNK D_80A0E2B0;
extern M2C_UNK D_80A0E358;

void func_8000214C(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x228), M2C_FIELD(arg0, s32 *, 0x244), M2C_FIELD(arg0, u8 *, 0x226), &D_80A0E2B0, &D_80A0E358, arg0);
    func_80A0DFD8(arg0, arg1);
}
