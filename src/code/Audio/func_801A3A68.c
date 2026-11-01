// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(s32);                         /* extern */
M2C_UNK AudioSeq_SetVolumeScale(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void Audio_PlaySubBgm(u16 arg0) {
    AudioSeq_SetVolumeScale(3, 3, 0x7F, 0);
    AudioSeq_QueueSeqCmd(arg0 | 0x03000000);
    AudioSeq_SetVolumeScale(0, 3, 0, 5);
    AudioSeq_QueueSeqCmd(0xC380030A);
    AudioSeq_QueueSeqCmd(0xC3900000);
}
