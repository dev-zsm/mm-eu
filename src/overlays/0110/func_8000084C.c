// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6009244;
extern M2C_UNK D_808D05E4;

void func_8000084C(u8 *arg0) {
    func_801377D0(arg0 + 0x144, &D_6009244, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808D05E4;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
