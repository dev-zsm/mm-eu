// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80112D7C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80115C10(s16);                         /* extern */

void func_80000D34(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s16 *, 0x1C2);
    switch (temp_v0) {                              /* irregular */
    case 1:
        func_80112D7C(arg0, 0x4D);
        break;
    case 2:
        func_80112D7C(arg0, 0x4E);
        break;
    case 3:
        func_80112D7C(arg0, 0x4F);
        break;
    case 4:
        func_80112D7C(arg0, 0x10);
        break;
    }
    func_80115C10((s16) (M2C_FIELD(arg0, s32 *, 0x16978) * -1));
}
