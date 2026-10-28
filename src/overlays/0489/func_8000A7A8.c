// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012CA60(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, s32, u8 *); /* extern */
extern M2C_UNK D_80B32E50;

void func_8000A7A8(u8 *arg0, s32 *arg1) {
    func_8012CA60(*arg1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x148), M2C_FIELD(arg0, s32 *, 0x164), M2C_FIELD(arg0, u8 *, 0x146), &D_80B32E50, 0, arg0);
}
