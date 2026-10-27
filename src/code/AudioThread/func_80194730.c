// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioThread_QueueCmd(s32, s32 *);

void AudioThread_QueueCmdS8(s32 a0, s8 a1) {
    s32 cmd;

    cmd = a1 << 24;

    AudioThread_QueueCmd(a0, &cmd);
}
