// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3438(s32, u8 *, M2C_UNK *, M2C_UNK *, s32, s32); /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BD9E0(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_80A05628;
extern M2C_UNK D_80A05C0C;
extern M2C_UNK D_80A05C18;
extern M2C_UNK D_80A05C44;

void func_80000A08(u8 *arg0, s32 arg1) {
    u8 *sp2C;

    sp2C = M2C_FIELD(arg0, u8 **, 0x120);
    M2C_FIELD(arg0, s16 *, 0x298) = 0;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B3438(arg1, arg0 + 0x24, &D_80A05C0C, &D_80A05C18, 5, 2);
    func_800B8C4C(arg0, 0x384B);
    func_800BD9E0(arg0 + 0x144, &D_80A05C44, 6);
    M2C_FIELD(sp2C, s16 *, 0x280) = (s16) (M2C_FIELD(sp2C, s16 *, 0x280) + 0x64);
    M2C_FIELD(arg0, M2C_UNK **, 0x294) = &D_80A05628;
}
