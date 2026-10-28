// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60033E4;
extern M2C_UNK D_808BD90C;

void func_80000FEC(u8 *arg0) {
    u8 temp_v0;

    func_801378E0(arg0 + 0x144, &D_60033E4, arg0);
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x18D);
    M2C_FIELD(arg0, s16 *, 0x190) = 3;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x18D) = (u8) (temp_v0 - 1);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BD90C;
}
