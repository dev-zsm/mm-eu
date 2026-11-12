#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0114.h"

f32 func_8008704C();                                /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_800015C8(u8 *arg0) {
    f32 temp_f6;

    M2C_FIELD(arg0, s16 *, 0x454) = func_800FF250(0x14, 0x14, arg0);
    temp_f6 = func_8008704C() * 10.0f;
    M2C_FIELD(arg0, s16 *, 0x456) = (s16) (s32) (temp_f6 + 3.0f);
    M2C_FIELD(arg0, f32 *, 0x414) = 0.0f;
    M2C_FIELD(arg0, s16 *, 0x45E) = (s16) M2C_FIELD(arg0, s16 *, 0x460);
}
