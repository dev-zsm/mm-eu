#include "types.h"

extern void AudioThread_QueueCmdS8(u32 arg0, s8 arg1);

void func_801A10B4(s8 arg0) {
    AudioThread_QueueCmdS8(0x46000002, arg0);
}
