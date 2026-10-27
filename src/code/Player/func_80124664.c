// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 Player_IsHoldingTwoHandedWeapon(void *arg0) {
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0x147);
    if ((temp_v0 >= 6) && (temp_v0 < 8)) {
        return 1;
    }
    return 0;
}
