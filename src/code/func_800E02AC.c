// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

u8 CollisionCheck_GetElementATDamage(s16 **arg0, void *arg1, s16 **arg2, M2C_UNK arg3) {
    s16 *temp_v0;
    s16 *temp_v0_2;

    temp_v0 = *arg0;
    if ((temp_v0 != NULL) && (*temp_v0 == 9)) {
        temp_v0_2 = *arg2;
        if ((temp_v0_2 != NULL) && (*temp_v0_2 == 0)) {
            return 8U;
        }
    }
    return M2C_FIELD(arg1, u8 *, 5);
}
