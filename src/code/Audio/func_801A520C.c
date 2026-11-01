// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_ScheduleProcessCmds();                            /* extern */
M2C_UNK Audio_DisableAllSeq();                            /* extern */
s32 Audio_GetEnabledNotesCount();                                /* extern */

void func_801A520C(void) {
    Audio_DisableAllSeq();
    AudioThread_ScheduleProcessCmds();
    do {

    } while (Audio_GetEnabledNotesCount() != 0);
}
