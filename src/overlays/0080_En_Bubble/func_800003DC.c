// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0080.h"

s32 func_8089ECF0();                                /* extern */

s32 func_800003DC(EnBubble *this) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(this, s16 *, 0x202);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(this, s16 *, 0x202) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(this, s16 *, 0x202);
    }
    if (var_v1 != 0) {
        return -1;
    }
    return func_8089ECF0();
}
