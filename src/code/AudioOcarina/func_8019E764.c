// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK);                     /* extern */
extern s8 D_801D145C;

void AudioOcarina_PlayCustomSequence(void) {
    D_801D145C = 1;
    AudioSeq_QueueSeqCmd(0x01000077);
}
