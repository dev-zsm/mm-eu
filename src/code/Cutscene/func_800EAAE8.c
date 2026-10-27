// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_SetSfxReverbIndexExceptOcarinaBank(M2C_UNK);                     /* extern */

void Cutscene_SetSfxReverbIndexTo2(s32 arg0, void *arg1, void *arg2) {
    if (M2C_FIELD(arg2, u16 *, 2) == M2C_FIELD(arg1, u16 *, 0x10)) {
        Audio_SetSfxReverbIndexExceptOcarinaBank(2);
    }
}
