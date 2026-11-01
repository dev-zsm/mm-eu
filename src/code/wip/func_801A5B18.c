#include "types.h"

typedef struct { u8 pad[16]; } Elem16;
extern Elem16 D_801F4AE8[];
void AudioThread_ScheduleProcessCmds(void);
void AudioSeq_StartSequence(s32 a, s32 b, s32 c, u16 d);
void AudioThread_QueueCmdS32(u32 op, void *data);
void AudioSfx_SetFreqAndStereoBits(void);
void Audio_SetAmbienceRandomBend(void);

void AudioSfx_Init(u16 seqId) {
    u8 i;

    AudioThread_ScheduleProcessCmds();
    AudioSeq_StartSequence(2, 0, 0x70, seqId);
    for (i = 0; i < 16; i++) {
        AudioThread_QueueCmdS32((((s32)i << 8) | 0x10020000), &D_801F4AE8[i]);
    }
    AudioThread_QueueCmdS32(0xE4000000, AudioSfx_SetFreqAndStereoBits);
    AudioThread_QueueCmdS32(0xE4000001, Audio_SetAmbienceRandomBend);
}
