// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_QueueCmdS32(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK AudioThread_ScheduleProcessCmds();                            /* extern */
M2C_UNK AudioSfx_Init(M2C_UNK);                     /* extern */
extern s8 D_801CF02C;
extern s8 D_801F4BEE;
extern s8 D_801F4C18;

void Audio_ResetForAudioHeapStep3(void) {
    AudioSfx_Init(1);
    AudioThread_QueueCmdS32(0xF2FF0000, 1);
    AudioThread_ScheduleProcessCmds();
    AudioThread_QueueCmdS32(0xF8000000, 0);
    D_801F4C18 = 0;
    D_801CF02C = 0;
    D_801F4BEE = 0;
}
