#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60007BC;

void func_80000310(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x2B2) == 2) {
        M2C_FIELD(arg0, s16 *, 0x2B2) = 0;
        func_80137788(arg0 + 0x144, &D_60007BC, 0x3F800000, 0, 7.0f, 2, -5.0f);
    }
}
