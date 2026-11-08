// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0607.h"

s16 func_800FF250(M2C_UNK, M2C_UNK, u8 *);        /* extern */

void func_800007D4(Actor *thisx) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x31C);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(thisx, s16 *, 0x31C) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(thisx, s16 *, 0x31C);
    }
    if (var_v1 == 0) {
        M2C_FIELD(thisx, s16 *, 0x31E) = (s16) (M2C_FIELD(thisx, s16 *, 0x31E) + 1);
        if (M2C_FIELD(thisx, s16 *, 0x31E) >= 4) {
            M2C_FIELD(thisx, s16 *, 0x31C) = func_800FF250(0x1E, 0x1E, thisx);
            M2C_FIELD(thisx, s16 *, 0x31E) = 0;
        }
    }
}
