// FLAGS: -O1 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B1300(s32, f32 *, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *, s32, s32); /* extern */
extern M2C_UNK D_801C9EE0;
extern M2C_UNK D_80A344E0;
extern M2C_UNK D_80A344E4;
extern M2C_UNK D_80A344E8;

void func_8000035C(u8 *arg0, s32 arg1) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;

    sp2C = M2C_FIELD(arg0, f32 *, 0x24);
    sp30 = M2C_FIELD(arg0, f32 *, 0x28) + 15.0f;
    sp34 = M2C_FIELD(arg0, f32 *, 0x2C);
    func_800B1300(arg1, &sp2C, &D_801C9EE0, &D_80A344E8, &D_80A344E0, &D_80A344E4, 0x15E, 0x14);
}
