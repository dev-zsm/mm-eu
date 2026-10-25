// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[5];
    u8 unk5;
    u8 unk6;
} Channel;

void AudioScript_SetChannelPriorities(Channel *channel, u8 priorities) {
    if ((priorities & 0xF) != 0) {
        channel->unk5 = priorities & 0xF;
    }
    priorities = priorities >> 4; // reusing the parameter gives the ROM's register choice
    if (priorities != 0) {
        channel->unk6 = priorities;
    }
}
