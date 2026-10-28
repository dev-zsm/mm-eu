// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_60013C4;
extern M2C_UNK D_80877ED0;

void func_800020B4(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_60013C4, 0xC1000000);
    M2C_FIELD(arg0, s16 *, 0x302) = 0;
    M2C_FIELD(arg0, s16 *, 0x304) = 0;
    func_800B8C4C(arg0, 0x3804);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 8);
    M2C_FIELD(arg0, M2C_UNK **, 0x2FC) = &D_80877ED0;
}
