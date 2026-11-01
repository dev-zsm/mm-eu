#include "types.h"

extern void AudioThread_QueueCmd(s32, s32 *, s32);

void AudioThread_QueueCmdU16(s32 arg0, u16 arg1) {
    s32 sp1C = arg1 << 16;

    AudioThread_QueueCmd(arg0, &sp1C, arg1);
}
