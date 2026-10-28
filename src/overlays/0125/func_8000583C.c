// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *);              /* extern */
M2C_UNK func_808E62E8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600F048;
extern M2C_UNK D_808E9F20;

void func_8000583C(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_600F048);
    func_808E62E8(arg0, 0x395D);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E9F20;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
