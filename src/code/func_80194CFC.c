// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioHeap_InitPool(M2C_UNK *, s32, M2C_UNK);     /* extern */
extern M2C_UNK D_801FAE80;

void AudioThread_InitExternalPool(s32 arg0, M2C_UNK arg1) {
    AudioHeap_InitPool(&D_801FAE80, arg0, arg1);
}
