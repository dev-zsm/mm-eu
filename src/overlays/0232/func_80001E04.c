// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_801A55BC();                                /* extern */
extern M2C_UNK D_8096FD44;

void func_80001E04(u8 *arg0, M2C_UNK arg1) {
    if (func_801A55BC() == 1) {
        M2C_FIELD(arg0, s16 *, 0x292) = 0xA;
        func_800B8C4C(arg0, 0x28D8);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096FD44;
    }
}
