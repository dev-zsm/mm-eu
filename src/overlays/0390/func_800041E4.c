// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80147CC4(u8 *);                      /* extern */
M2C_UNK func_80151E7C(u8 *, M2C_UNK);             /* extern */
s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_80A99DE0(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80A9DD08;

void func_800041E4(u8 *arg0, u8 *arg1) {
    u16 temp_v0;

    func_80137070(arg0 + 0x148);
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        temp_v0 = M2C_FIELD(arg1, u16 *, 0x16810);
        switch (temp_v0) {                          /* irregular */
        case 0x8E5:
            func_80151E7C(arg1, 0x8E6);
            func_80A99DE0(arg0, 3);
            return;
        case 0x8E6:
            func_80151E7C(arg1, 0x8E7);
            func_80A99DE0(arg0, 5);
            return;
        case 0x8E7:
            func_80147CC4(arg1);
            M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9DD08;
            func_80A99DE0(arg0, 0);
            break;
        }
    }
}
