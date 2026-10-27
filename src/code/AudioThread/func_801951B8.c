// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_QueueCmdS32(s32, s32, s32);               /* extern */

void AudioThread_Noop2Cmd(s32 arg0, s32 arg1) {
    AudioThread_QueueCmdS32((arg1 & 0xFF) | 0xFD000000, arg0, arg1);
}
