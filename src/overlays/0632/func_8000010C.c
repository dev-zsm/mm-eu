// COMPILER: ido53
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0632.h"

f32 func_8008704C();                                /* extern */
extern f32 D_80BF5470;

void func_8000010C(u8 *arg0) {
    u8 temp_t6;
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x2AC);
    temp_t6 = temp_v0 + 1;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x2AC) = temp_t6;
        if ((temp_t6 & 0xFF) == 4) {
            M2C_FIELD(arg0, u8 *, 0x2AC) = 0U;
        }
    } else if (func_8008704C() < D_80BF5470) {
        M2C_FIELD(arg0, u8 *, 0x2AC) = (u8) (M2C_FIELD(arg0, u8 *, 0x2AC) + 1);
    }
}
