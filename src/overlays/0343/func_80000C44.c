// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A36DD4();                            /* extern */
extern s32 D_801EAB9C;

void func_80000C44(u8 *arg0, u8 *arg1) {
    if ((M2C_FIELD(arg1, u8 *, 0x1F2C) != 0) && ((M2C_FIELD(arg0, s16 *, 0x1C) & 0x3C) == 4) && (M2C_FIELD(arg1, s16 *, 0xA4) == 8) && (D_801EAB9C == 2)) {
        func_80A36DD4();
    }
}
