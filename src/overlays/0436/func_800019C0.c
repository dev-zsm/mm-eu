// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
extern s8 D_801EACC4;
extern M2C_UNK D_80AD0158;

void func_800019C0(u8 *arg0, M2C_UNK arg1) {
    func_8019FF78(0x482C);
    M2C_FIELD(arg0, s16 *, 0x354) = 0;
    D_801EACC4 = 6;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AD0158;
}
