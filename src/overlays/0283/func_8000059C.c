// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B701C(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
extern s8 D_801EACC4;
extern M2C_UNK D_809B4B58;

void func_8000059C(u8 *arg0, s32 arg1) {
    D_801EACC4 = 0;
    func_80151DF4(arg1, 0xE95, 0);
    func_800B701C(arg1, arg0, 7);
    func_801A9868(0x101400FF);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809B4B58;
}
