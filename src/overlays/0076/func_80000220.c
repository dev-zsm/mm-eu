// COMPILER: ido53
#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
extern f32 D_8089DAF0;

void func_80000220(u8 *arg0) {
    u8 temp_t6;
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0x289);
    temp_t6 = temp_v0 + 1;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8 *, 0x289) = temp_t6;
        if ((temp_t6 & 0xFF) == 4) {
            M2C_FIELD(arg0, u8 *, 0x289) = 0U;
        }
    } else if (func_8008704C() < D_8089DAF0) {
        M2C_FIELD(arg0, u8 *, 0x289) = 1U;
    }
}
