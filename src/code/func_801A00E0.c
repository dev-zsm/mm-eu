// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_PlaySfx(M2C_UNK);                     /* extern */
M2C_UNK AudioSfx_StopById(M2C_UNK);                     /* extern */

void Audio_PlaySfx_MessageCancel(void) {
    Audio_PlaySfx(0x480A);
    AudioSfx_StopById(0x4818);
}
