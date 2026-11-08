// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0099.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_60033E4;
extern M2C_UNK D_808BD90C;

void func_80000FEC(Actor *thisx) {
    u8 temp_v0;

    func_801378E0((u8 *)thisx + 0x144, &D_60033E4, thisx);
    temp_v0 = M2C_FIELD(thisx, u8 *, 0x18D);
    M2C_FIELD(thisx, s16 *, 0x190) = 3;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
    if (temp_v0 != 0) {
        M2C_FIELD(thisx, u8 *, 0x18D) = (u8) (temp_v0 - 1);
    }
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_808BD90C;
}
