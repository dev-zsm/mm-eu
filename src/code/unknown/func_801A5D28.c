// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_QueueCmdS32(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK AudioSfx_ResetSfxChannelState();                            /* extern */
M2C_UNK Audio_ResetData();                            /* extern */
M2C_UNK AudioSfx_Init(M2C_UNK);                     /* extern */
M2C_UNK AudioVoice_ResetWord();                            /* extern */
M2C_UNK AudioSeq_ResetActiveSequences();                            /* extern */

void func_801A5D28(void) {
    AudioSeq_ResetActiveSequences();
    AudioThread_QueueCmdS32(0xF2FF0000, 1);
    Audio_ResetData();
    AudioSfx_ResetSfxChannelState();
    AudioSfx_Init(1);
    AudioVoice_ResetWord();
}
