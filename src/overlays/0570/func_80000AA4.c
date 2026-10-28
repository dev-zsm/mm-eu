// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK D_80BB661C(u8 *, M2C_UNK);                /* extern */
s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8398(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_800EE03C(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80BB6344(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_80BB63AC(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80BB6504(u8 *);                      /* extern */
M2C_UNK func_80BB6990(u8 *, M2C_UNK);             /* extern */

void func_80000AA4(u8 *arg0, M2C_UNK arg1) {
    func_80BB6504(arg0);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x330) = D_80BB661C;
        func_80BB63AC(arg0, arg1);
    } else if (func_80BB6344(arg0, arg1) != 0) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
    if (func_800EE03C(arg1, 0x1F8) != 0) {
        M2C_FIELD(arg0, M2C_UNK (**)(u8 *, M2C_UNK), 0x330) = func_80BB6990;
        func_80BB6990(arg0, arg1);
    }
}
