#include "types.h"
#include "m2c_compat.h"

s32 func_80087010();                          /* extern */
M2C_UNK func_80A0D758();                      /* extern */
M2C_UNK func_80A0DC04();                      /* extern */

void func_800018A0(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v1;

    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (func_80087010() >> 0x16);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (func_80087010(arg0) >> 0x16);
    temp_v1 = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x120), s16 *, 0x1C);
    if ((temp_v1 == 7) || (temp_v1 == 8)) {
        func_80A0D758(arg0);
        return;
    }
    if (temp_v1 == 9) {
        func_80A0DC04(arg0);
    }
}
