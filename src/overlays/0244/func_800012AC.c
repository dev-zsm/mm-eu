// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012CA60(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_809821EC;
extern M2C_UNK D_8098223C;

void func_800012AC(u8 *arg0, s32 *arg1) {
    func_8012CA60(*arg1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x1E0), M2C_FIELD(arg0, s32 *, 0x1FC), M2C_FIELD(arg0, u8 *, 0x1DE), &D_809821EC, &D_8098223C, arg0);
}
