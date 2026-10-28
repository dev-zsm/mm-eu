// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6002510;
extern M2C_UNK D_80ABCC40;

void func_800010F0(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6002510, 0xC0400000);
    func_800B8C4C(arg0, 0x38F7);
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80ABCC40;
}
