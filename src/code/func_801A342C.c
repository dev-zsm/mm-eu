// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_StartSceneSequence(u16);                         /* extern */
M2C_UNK Audio_PlaySequenceWithSeqPlayerIO(M2C_UNK, u16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK Audio_PlayAmbience(M2C_UNK);                     /* extern */
M2C_UNK AudioSeq_QueueSeqCmd(M2C_UNK);                     /* extern */

void Audio_StartMorningSceneSequence(u16 arg0) {
    if (arg0 != 1) {
        AudioSeq_QueueSeqCmd(0x140000FF);
        Audio_StartSceneSequence(arg0);
        Audio_PlaySequenceWithSeqPlayerIO(0, arg0, 0, 0, 1);
        return;
    }
    Audio_PlayAmbience(8);
}
