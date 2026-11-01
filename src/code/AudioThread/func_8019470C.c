// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"
void AudioThread_QueueCmdS32(s32 a0, s32 a1) {
    AudioThread_QueueCmd(a0, &a1);
}
