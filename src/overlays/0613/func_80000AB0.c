// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8013CD14(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80BE2080(u8 *);                      /* extern */
M2C_UNK func_80BE2144(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BE2690(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BE2724(u8 *, M2C_UNK);             /* extern */

void func_80000AB0(u8 *arg0, M2C_UNK arg1) {
    func_80BE2690(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    func_80BE2724(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x1D8) != 0) {
        func_80BE2080(arg0);
        func_8013CD14(arg0, arg1, 0x42700000, 0x41200000, 0, M2C_FIELD(arg0, u16 *, 0x234) & 7);
        func_800B64E0(arg0, 0x41D00000);
        func_80BE2144(arg0, arg1);
    }
}
