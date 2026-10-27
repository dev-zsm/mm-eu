// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
s32 func_801529DC(s32);                             /* extern */

s32 MsgEvent_AwaitText(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_v0;

    temp_v0 = func_801529DC(arg1 + 0x4908);
    if (temp_v0 != 2) {
        if ((temp_v0 == 4) || (temp_v0 == 5)) {
            if (func_80147B34(arg1) == 0) {
                return 1;
            }
            goto block_6;
        }
        return 1;
    }
block_6:
    return 0;
}
