// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800C604C(s32, s32, s32, s32);          /* extern */
M2C_UNK func_80BFD28C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80BFD6C8;

void func_80000684(u8 *arg0, s32 arg1) {
    func_800C604C(arg1, arg1 + 0x880, M2C_FIELD(arg0, s32 *, 0x144), arg1);
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    func_80BFD28C(arg0, arg1);
    func_800B8C4C(arg0, 0x2810);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BFD6C8;
}
