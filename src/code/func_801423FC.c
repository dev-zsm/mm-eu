// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80086E40(M2C_UNK);                         /* extern */
M2C_UNK VisMono_DesaturateTLUT(s32);                         /* extern */
M2C_UNK VisMono_DesaturateDList(s32);                         /* extern */

void VisMono_DrawOld(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;

    if (M2C_FIELD(arg0, s32 *, 0x10) == 0) {
        temp_v0 = func_80086E40(0x200);
        M2C_FIELD(arg0, s32 *, 0x10) = temp_v0;
        VisMono_DesaturateTLUT(temp_v0);
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        temp_v0_2 = func_80086E40(0x2338);
        M2C_FIELD(arg0, s32 *, 0x14) = temp_v0_2;
        VisMono_DesaturateDList(temp_v0_2);
    }
}
