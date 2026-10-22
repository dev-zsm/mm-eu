// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_QueueSeqCmd(s32);                         /* extern */
extern u16 D_801CEFFC;

void Audio_ForceRestorePreviousBgm(void) {
    if (D_801CEFFC != 0xFFFF) {
        AudioSeq_QueueSeqCmd(D_801CEFFC + 0x8000);
    }
    D_801CEFFC = 0xFFFF;
}
