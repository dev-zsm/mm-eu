// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioPlayback_SeqLayerNoteRelease(s32);                         /* extern */

void func_80197278(void *arg0, s32 arg1) {
    AudioPlayback_SeqLayerNoteRelease(M2C_FIELD(arg0, s32 *, 0x48));
    M2C_FIELD(arg0, s32 *, 0x44) = arg1;
}
