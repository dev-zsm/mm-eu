// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_8013B284(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80A35B58(u8 *, s32);                     /* extern */
extern M2C_UNK D_80A35C98;

s32 func_80000100(u8 *arg0, s32 arg1) {
    if (!(M2C_FIELD(arg0, u16 *, 0x18C) & 7) || (func_800B8254(arg0, arg1) == 0)) {
        return 0;
    }
    func_8013B284(arg0 + 0x18C, 0, 7);
    M2C_FIELD(arg0, s32 *, 0x190) = func_80A35B58(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80A35C98;
    return 1;
}
