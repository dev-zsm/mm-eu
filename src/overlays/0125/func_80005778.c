// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
M2C_UNK func_808E62E8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_60010F4;
extern M2C_UNK D_808E9E64;

void func_80005778(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_60010F4, arg0);
    M2C_FIELD(arg0, s16 *, 0x2B6) = (s16) (M2C_FIELD(arg0, s16 *, 0x2D0) + 0x8000);
    func_808E62E8(arg0, 0x395F);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808E9E64;
}
