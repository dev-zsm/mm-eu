// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_6001ABC;
extern M2C_UNK D_8090F0AC;

void func_80000C60(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6001ABC);
    func_800B8C4C(arg0, 0x39B2);
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090F0AC;
}
