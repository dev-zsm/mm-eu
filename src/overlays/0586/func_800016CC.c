// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013CD14(u8 *, M2C_UNK, s32, M2C_UNK, s32, s32); /* extern */
M2C_UNK func_80BC2FF0(u8 *);                      /* extern */
M2C_UNK func_80BC30B8(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BC39CC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BC3BFC(u8 *);                      /* extern */
M2C_UNK func_80BC3E04(u8 *, M2C_UNK);             /* extern */

void func_800016CC(u8 *arg0, M2C_UNK arg1) {
    func_80BC39CC(arg0, arg1);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x188)(arg0, arg1);
    func_80BC3E04(arg0, arg1);
    if (M2C_FIELD(arg0, u8 *, 0x35C) != 0) {
        func_80BC2FF0(arg0);
        func_80BC3BFC(arg0);
        func_8013CD14(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x4D4), 0x41F00000, M2C_FIELD(arg0, s32 *, 0x4F0), M2C_FIELD(arg0, u16 *, 0x4C2) & 7);
        func_80BC30B8(arg0, arg1);
    }
}
