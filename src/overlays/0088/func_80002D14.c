// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
extern M2C_UNK D_6012C34;
extern M2C_UNK D_6013320;
extern M2C_UNK D_808AB578;

void func_80002D14(u8 *arg0, s32 arg1) {
    func_80136ED0(arg1, arg0 + 0x144, &D_6013320, &D_6012C34, arg0 + 0x31E, arg0 + 0x390, 0x13);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_808AB578;
}
