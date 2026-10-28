// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80917274();                            /* extern */
extern M2C_UNK D_80917FA8;

void func_80000FF0(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0xBD6) = 1;
    M2C_FIELD(arg0, s16 *, 0xBCA) = 0x50;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80917FA8;
    func_80917274();
}
