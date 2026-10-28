// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800C9F78(s32, s32, s32, s32, u8 *, M2C_UNK *); /* extern */

void func_800004FC(u8 *arg0, s32 arg1) {
    s32 pad[2];
    M2C_UNK sp2C;

    func_800C9F78(arg1, arg1 + 0x830, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x2C), arg0 + 0x160, &sp2C);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x15C)(arg0, arg1);
}
