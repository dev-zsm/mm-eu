// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_801342C8(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_8093EC40;
extern M2C_UNK D_8093EC88;

void func_80000EF8(u8 *arg0, s32 *arg1) {
    func_8012C73C(*arg1);
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x194), M2C_FIELD(arg0, s32 *, 0x1B0), M2C_FIELD(arg0, u8 *, 0x192), &D_8093EC40, &D_8093EC88, arg0);
}
