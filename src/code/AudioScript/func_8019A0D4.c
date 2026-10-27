// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioScript_SequenceChannelSetVolume(u8 *a0, u8 a1) {
    *(f32 *)(a0 + 0x30) = (s32)a1 / 127.0f;
}
