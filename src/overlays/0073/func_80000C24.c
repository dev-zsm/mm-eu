// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_600069C;
extern M2C_UNK D_80893B74;

void func_80000C24(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_600069C);
    M2C_FIELD(arg0, M2C_UNK **, 0x2B4) = &D_80893B74;
}
