// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void AudioThread_QueueCmd(s32 a0, s32 *p);
void AudioThread_QueueCmdS32(s32 a0, s32 a1) {
    AudioThread_QueueCmd(a0, &a1);
}
