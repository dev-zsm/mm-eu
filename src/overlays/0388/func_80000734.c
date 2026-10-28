// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A96F98(u8 *, u8 *);              /* extern */
M2C_UNK func_80A971EC(u8 *, u8 *);              /* extern */

void func_80000734(u8 *arg0, u8 *arg1) {
    func_80137070(arg0 + 0x144);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, u8 *), 0x200)(arg0, arg1);
    func_80A96F98(arg0, arg1);
    func_80A971EC(arg0, arg1);
    if ((M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) && (M2C_FIELD(arg0, u8 *, 0x22E) != 0) && (M2C_FIELD(arg0, s16 *, 0x1C) & 0x100)) {
        func_800B8C4C(arg0, 0x304A);
    }
}
