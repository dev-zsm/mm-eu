// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6003584;
extern M2C_UNK D_8097A6DC;

void func_80001144(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_6003584, 0xBF800000, (f32) func_80134AE8(&D_6003584), 0.0f, 2, -4.0f);
    M2C_FIELD(arg0, s8 *, 0x3E4) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    func_800B8C4C(arg0, 0x3987);
    M2C_FIELD(arg0, s16 *, 0x3DE) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x228) = &D_8097A6DC;
}
