// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80088070(s32, M2C_UNK, M2C_UNK);       /* extern */
extern s32 D_801FFE3C;

void AudioThread_WaitForAudioTask(void) {
    func_80088070(D_801FFE3C, 0, 0);
    func_80088070(D_801FFE3C, 0, 1);
}
