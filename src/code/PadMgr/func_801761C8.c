// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80088070(s32, s32 *, M2C_UNK);         /* extern */
extern s32 D_801C9E40;

s32 PadMgr_VoiceAcquireSerialEventQueue(void) {
    s32 sp1C;

    func_80088070(D_801C9E40 + 0x4C, &sp1C, 1);
    return sp1C;
}
