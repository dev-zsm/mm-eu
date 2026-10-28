// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800FEC70(s32, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK D_80866240;

void func_800008F0(u8 *arg0, M2C_UNK arg1) {
    if (func_800FEC70(arg0 + 0x32, 0, 0x700) != 0) {
        func_800B8C4C(arg0, 0x2801);
        M2C_FIELD(arg0, M2C_UNK **, 0x1C8) = &D_80866240;
    }
}
