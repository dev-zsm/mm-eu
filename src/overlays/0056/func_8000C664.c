// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80839724();                            /* extern */
extern s32 D_80862224;

s32 func_8000C664(u8 *arg0, M2C_UNK arg1) {
    if ((D_80862224 == 0) && (M2C_FIELD(arg0, u8 *, 0x14B) == 2)) {
        func_80839724();
    }
    return 0;
}
