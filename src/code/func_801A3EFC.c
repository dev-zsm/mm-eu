// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK);                     /* extern */
M2C_UNK AudioSeq_SetVolumeScale(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void Audio_MuteBgmPlayersForFanfare(void) {
    AudioSeq_SetVolumeScale(0, 1, 0, 5);
    AudioSeq_SetVolumeScale(3, 1, 0, 5);
    AudioSeq_QueueSeqCmd(0xC180010A);
    AudioSeq_QueueSeqCmd(0xC183010A);
    AudioSeq_QueueSeqCmd(0xC1900000);
}
