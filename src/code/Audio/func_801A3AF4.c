// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK);                     /* extern */
s32 AudioSeq_GetActiveSeqId(M2C_UNK);                         /* extern */
s32 AudioSeq_IsSeqCmdNotQueued(M2C_UNK, M2C_UNK);                /* extern */

void Audio_IncreaseTempoForTimedMinigame(void) {
    if ((AudioSeq_GetActiveSeqId(0) == 0x25) && (AudioSeq_IsSeqCmdNotQueued(0, 0xF0000000) != 0)) {
        AudioSeq_QueueSeqCmd(0xB00500D2);
    }
}
