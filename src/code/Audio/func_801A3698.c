// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK);                     /* extern */
s32 AudioSeq_GetActiveSeqId(M2C_UNK);                         /* extern */

void Audio_PlayBgmForSongOfStorms(void) {
    if (AudioSeq_GetActiveSeqId(0) != 0x2E) {
        AudioSeq_QueueSeqCmd(0x802E);
    }
}
