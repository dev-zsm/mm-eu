#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80137C58(u8 *, f32);                 /* extern */
M2C_UNK func_80A3C354(u8 *);                      /* extern */

void func_80001398(u8 *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(arg0, s16 *, 0x18E) == 3) && (func_80137C58(arg0 + 0x144, 5.0f) != 0)) {
        func_800B8C4C(arg0, 0x3855);
    }
    if (func_80137C58(arg0 + 0x144, 0) != 0) {
        M2C_FIELD(arg0, s16 *, 0x18E) = (s16) (M2C_FIELD(arg0, s16 *, 0x18E) - 1);
        if (M2C_FIELD(arg0, s16 *, 0x18E) == 0) {
            func_80A3C354(arg0);
        }
    }
}
