// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x4448];
    u8 unk4448;
    u8 unk4449;
    u8 pad444A[0x353E];
    s32 unk7988;
} AudioCtx;

extern AudioCtx D_801F84B0;

void AudioThread_WaitForAudioResetQueueP(void);
void AudioThread_ResetCmdQueue(void);
void AudioThread_QueueCmdS32(u32 a, s32 b);
s32 AudioThread_ScheduleProcessCmds(void);
void func_80088070(s32 a, void *b, s32 c, s32 d);

s32 AudioThread_ResetAudioHeap(s32 specId) {
    s32 cur;
    s32 sp20;
    s32 pad[2];

    AudioThread_WaitForAudioResetQueueP();
    cur = D_801F84B0.unk4448;
    if (cur != 0) {
        AudioThread_ResetCmdQueue();
        if (specId == D_801F84B0.unk4449) {
            return -2;
        }
        if (cur >= 3) {
            D_801F84B0.unk4449 = specId;
            return -3;
        }
        func_80088070(D_801F84B0.unk7988, &sp20, 1, specId);
    }
    AudioThread_WaitForAudioResetQueueP();
    AudioThread_QueueCmdS32(0xF9000000, specId);
    return AudioThread_ScheduleProcessCmds();
}
