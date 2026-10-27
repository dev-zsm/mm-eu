// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_SetVolumeScale(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void Audio_SetBgmVolumeOn(void) {
    AudioSeq_SetVolumeScale(0, 1, 0x7F, 3);
    AudioSeq_SetVolumeScale(3, 1, 0x7F, 3);
}
