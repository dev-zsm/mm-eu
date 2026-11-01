// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_QueueCmdS32(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK AudioThread_ScheduleProcessCmds();                            /* extern */

void Audio_DisableAllSeq(void) {
    AudioThread_QueueCmdS32(0x83000000, 0);
    AudioThread_QueueCmdS32(0x83010000, 0);
    AudioThread_QueueCmdS32(0x83020000, 0);
    AudioThread_QueueCmdS32(0x83030000, 0);
    AudioThread_QueueCmdS32(0x83040000, 0);
    AudioThread_ScheduleProcessCmds();
}
