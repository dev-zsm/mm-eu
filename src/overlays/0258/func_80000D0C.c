#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_8098BD4C;
extern f32 D_8098DBA0;

void func_80000D0C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x37A) = (s16) -M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0x2B0) = func_800FF250(0x1E, 0x1E, arg0);
    M2C_FIELD(arg0, s16 *, 0x37C) = (s16) (s32) ((f32) (M2C_FIELD(arg0, s16 *, 0x32) - M2C_FIELD(arg0, s16 *, 0x37A)) * D_8098DBA0);
    M2C_FIELD(arg0, s16 *, 0x358) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8098BD4C;
}
