// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B680C(s32);                         /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A7CB2C(s32);                         /* extern */

void func_80003418(s32 arg0, u8 *arg1) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if ((s32) M2C_FIELD(arg1, u8 *, 0x16C68) >= 8) {
        M2C_FIELD(temp_v0, s32 *, 0xA6C) = (s32) (M2C_FIELD(temp_v0, s32 *, 0xA6C) & ~0x20);
        func_80A7CB2C(arg0);
    }
    func_800B680C(arg0);
    func_80137070(arg0 + 0x148);
}
