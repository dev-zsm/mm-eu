// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern void AudioThread_QueueCmdS32(u32, s32);
extern void Audio_MuteBgmPlayersForFanfare(void);
extern void AudioSeq_QueueSeqCmd(u32);
extern s32 AudioSeq_GetActiveSeqId(s32);
extern s32 AudioSeq_IsSeqCmdNotQueued(u32, u32);
extern u8 D_801F4BEB;
extern u16 D_801F4BEC;
void Audio_UpdateFanfare(void) {
    if (D_801F4BEB != 0) {
        if ((D_801F4BEB != 5) && (AudioSeq_IsSeqCmdNotQueued(0x11000000, 0xFF000000) == 0)) {
            D_801F4BEB = 0;
            return;
        }
        D_801F4BEB--;
        if (D_801F4BEB == 0) {
            AudioThread_QueueCmdS32(0xE3000000, 0);
            AudioThread_QueueCmdS32(0xE3000000, 1);
            AudioSeq_GetActiveSeqId(0);
            if (AudioSeq_GetActiveSeqId(1) == 0xFFFF) {
                Audio_MuteBgmPlayersForFanfare();
            }
            AudioSeq_QueueSeqCmd(D_801F4BEC | 0x01000000);
            AudioSeq_QueueSeqCmd(0xA000FFFF);
        }
    }
}
