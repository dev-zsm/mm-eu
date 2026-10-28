// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6000998;
extern M2C_UNK D_80B30498;

void func_80007D74(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6000998, 0xC0C00000);
    M2C_FIELD(arg0, M2C_UNK **, 0x2EC) = &D_80B30498;
}
