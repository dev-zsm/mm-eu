#include "types.h"
#include "m2c_compat.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_80900160;

void func_80000D78(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = func_800FF250(0x78, 0x32, arg0);
    M2C_FIELD(arg0, s16 *, 0x310) = 0;
    M2C_FIELD(arg0, s16 *, 0x30E) = (s16) M2C_FIELD(arg0, s16 *, 0x310);
    M2C_FIELD(arg0, s16 *, 0x312) = temp_v0;
    M2C_FIELD(arg0, M2C_UNK **, 0x308) = &D_80900160;
    M2C_FIELD(arg0, u16 *, 0x30C) = (u16) (M2C_FIELD(arg0, u16 *, 0x30C) & 0xFEFF);
}
