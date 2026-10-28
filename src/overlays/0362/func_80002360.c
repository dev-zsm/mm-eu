// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801342C8(s32, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80A58294;
extern M2C_UNK D_80A582CC;

void func_80002360(u8 *arg0, s32 arg1) {
    func_801342C8(arg1, M2C_FIELD(arg0, s32 *, 0x14C), M2C_FIELD(arg0, s32 *, 0x168), M2C_FIELD(arg0, u8 *, 0x14A), &D_80A58294, &D_80A582CC, arg0);
}
