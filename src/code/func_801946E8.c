// FLAGS: -O2 -g3 -mips2
#include "types.h"

void AudioThread_QueueCmd(void *, f32 *);

void AudioThread_QueueCmdF32(void *arg0, f32 arg1) {
    AudioThread_QueueCmd(arg0, &arg1);
}
