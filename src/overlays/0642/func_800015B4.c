// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012CA60(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, s32, s32, u8 *); /* extern */

void func_800015B4(u8 *arg0, s32 *arg1) {
    func_8012CA60(*arg1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x174), M2C_FIELD(arg0, s32 *, 0x190), M2C_FIELD(arg0, u8 *, 0x172), 0, 0, arg0);
}
