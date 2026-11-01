// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioOcarina_ResetAndMute();                            /* extern */
M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK);                     /* extern */
extern s8 D_801CF8E8;

void AudioOcarina_ResetInstrument(void) {
    if (D_801CF8E8 != 0) {
        AudioSeq_QueueSeqCmd(0x82010D00);
        D_801CF8E8 = 0;
        AudioOcarina_ResetAndMute();
    }
}
