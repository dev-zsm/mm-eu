// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"


void AudioSfx_StopByPos(s32 *pos) {
    u8 bank;
    s32 pad[11]; // unused: the ROM frame is larger than the live locals need
    s32 *sp24;

    for (bank = 0; bank < 7; bank++) {
        AudioSfx_StopByPosAndBankImpl(bank, pos);
    }
    sp24 = pos;
    AudioSfx_RemoveMatchingRequests(2, &sp24);
}
