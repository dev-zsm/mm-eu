// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_QueueCmdS32(s32, M2C_UNK);                /* extern */

void AudioThread_Noop1Cmd(s32 arg0, s32 arg1, s32 arg2) {
    AudioThread_QueueCmdS32(((arg0 & 0xFF) << 0x10) | 0xFA000000 | ((arg1 & 0xFF) << 8) | (arg2 & 0xFF), 1);
}
