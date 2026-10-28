// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B02EC(s32, s32);                    /* extern */
M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_800E1F64(s32, s32);                    /* extern */

void func_80004990(u8 *arg0, s32 arg1) {
    func_800E0FAC(arg1, arg0 + 0x194);
    func_800E1F64(arg1, arg0 + 0x22C);
    func_800B02EC(arg1, M2C_FIELD(arg0, s32 *, 0x3E8));
}
