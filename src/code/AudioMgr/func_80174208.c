// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK func_80088070(s32, M2C_UNK, M2C_UNK, s32);  /* extern */

void AudioMgr_Unlock(struct AudioMgr *audioMgr) {
    func_80088070((u8 *)audioMgr + 0x110, 0, 1, audioMgr);
}
