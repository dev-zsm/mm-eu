// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A3C04(s32);                         /* extern */

void CutsceneCmd_StopSequence(s32 arg0, void *arg1, void *arg2) {
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg1, u16 *, 0x10);
    if (((s32) temp_v0 >= (s32) M2C_FIELD(arg2, u16 *, 2)) && ((s32) M2C_FIELD(arg2, u16 *, 4) >= (s32) temp_v0)) {
        func_801A3C04((M2C_FIELD(arg2, u16 *, 0) - 1) & 0xFFFF);
    }
}
