// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_StartSequence(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void Audio_StartSfxPlayer(void) {
    AudioSeq_StartSequence(2, 0, 0xFF, 5);
}
