#include "types.h"
#include "m2c_compat.h"
void func_800B8C4C(u8 *a, s32 b);

void func_800003D4(u8 *a) {
    s16 v = M2C_FIELD(a, s16 *, 0xBE);

    M2C_FIELD(a, s16 *, 0xBE) += M2C_FIELD(a, s16 *, 0x20A);
    if (v < 0 && M2C_FIELD(a, s16 *, 0xBE) > 0) {
        func_800B8C4C(a, 0x38EE);
    }
}
