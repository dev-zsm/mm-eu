// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80087CB0(s32, s32, M2C_UNK);           /* extern */
extern s32 D_801C9E40;

void PadMgr_ReleaseSerialEventQueue(s32 arg0) {
    func_80087CB0(D_801C9E40 + 0x4C, arg0, 1);
}
