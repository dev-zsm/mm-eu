// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80112D7C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80115C10(s16);                         /* extern */

void func_80000C34(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg1, s16 *, 0x1C2);
    switch (temp_v0) {                              /* irregular */
    case 5:
        func_80112D7C(arg0, 0x8F);
        break;
    case 10:
        func_80112D7C(arg0, 0x90);
        break;
    case 20:
        func_80112D7C(arg0, 0x91);
        break;
    case 30:
        func_80112D7C(arg0, 0x92);
        break;
    }
    func_80115C10((s16) (M2C_FIELD(arg0, s32 *, 0x16978) * -1));
}
