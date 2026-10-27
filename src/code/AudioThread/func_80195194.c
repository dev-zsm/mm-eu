// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_QueueCmdS32(M2C_UNK, M2C_UNK);            /* extern */

void AudioThread_Noop1CmdZeroed(void) {
    AudioThread_QueueCmdS32(0xFA000000, 0);
}
