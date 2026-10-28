// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8019FF78(M2C_UNK);                     /* extern */
M2C_UNK func_809F15DC(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_809F27DC;

void func_80000B78(s32 arg0, u8 *arg1) {
    func_8019FF78(0x4809);
    M2C_FIELD(arg1, s8 *, 0x321) = 0;
    func_809F15DC(arg1, &D_809F27DC);
}
