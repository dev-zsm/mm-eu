// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80088070(s32, M2C_UNK, M2C_UNK, s32);  /* extern */

void AnimTask_LoadPlayerFrame(s32 arg0, s32 arg1) {
    func_80088070(arg1 + 0x20, 0, 1, arg1);
}
