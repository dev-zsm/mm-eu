// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, M2C_UNK);       /* extern */
extern M2C_UNK D_809B4CC4;

void func_80000600(u8 *arg0, s32 arg1) {
    func_80151DF4(arg1, 0xE97, 0);
    func_800B701C(arg1, arg0, 7);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809B4CC4;
}
