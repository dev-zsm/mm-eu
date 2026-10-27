// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801CF014;
extern u8 D_801CF01C;
extern u16 D_801F83FA;
void AudioThread_QueueCmdS8(s32, s8);
void Audio_SetExtraFilter(u8 a) {
    s8 b = a;
    s32 i;
    D_801CF01C = a;
    D_801CF014 = a;
    if (D_801F83FA == 1) {
        for (i = 0; i < 16; i = (i + 1) & 0xFF) {
            AudioThread_QueueCmdS8(((i & 0xFF) << 8) | 0x06040000 | 6, b);
        }
    }
}
