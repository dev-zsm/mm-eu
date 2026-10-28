// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_809742D8(u8 *);                      /* extern */
extern M2C_UNK D_80974488;

void func_800004E8(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F, arg1) != 0) {
        func_800B6490(arg0);
        return;
    }
    func_800FF8DC(arg0, &D_80974488);
    func_809742D8(arg0);
}
