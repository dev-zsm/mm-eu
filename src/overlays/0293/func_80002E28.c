// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
extern M2C_UNK D_6009120;
extern M2C_UNK D_6009220;
extern M2C_UNK D_809F5338;

void func_80002E28(u8 *arg0, s32 arg1) {
    func_80136ED0(arg1, arg0 + 0x144, &D_6009220, &D_6009120, arg0 + 0x1F2, arg0 + 0x26A, 0x10);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_809F5338;
    M2C_FIELD(arg0, s32 *, 0x190) = 0;
    M2C_FIELD(arg0, f32 *, 0x160) = 2.0f;
}
