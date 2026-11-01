// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"


void Audio_MuteSeqPlayerBgmSub(u8 flag) {
    if (flag == 1) {
        AudioThread_QueueCmdS32(0xF1030000, 0);
    } else {
        AudioThread_QueueCmdS32(0xF2030000, 0);
    }
}
