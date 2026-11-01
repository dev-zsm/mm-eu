// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK);                     /* extern */

void Audio_StopSubBgm(void) {
    AudioSeq_QueueSeqCmd(0x130000FF);
}
