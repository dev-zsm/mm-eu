// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEFE0;
extern s8 D_801CF02C;
extern u8 D_801F4BF0;
extern u8 D_801F4C19;
extern u8 D_801F4C1A;
extern u8 D_801F4C20[];

void Audio_StartObjSoundFanfare(s32, void *, s8, s32);
void Audio_MuteBgmPlayersForFanfare();
void Audio_PlayAmbience(s32);
void AudioSeq_QueueSeqCmd(s32);
u16 AudioSeq_GetActiveSeqId(s32);

void Audio_UpdateObjSoundFanfare(void) {
    if ((D_801F4C1A != 0) && (D_801F4BF0 == 0)) {
        if (D_801F4C19 != 0) {
            Audio_StartObjSoundFanfare(1, D_801F4C20, D_801F4C19, 0);
            if (AudioSeq_GetActiveSeqId(1) == 0xFFFF) {
                Audio_MuteBgmPlayersForFanfare();
            }
            if ((AudioSeq_GetActiveSeqId(0) != 0xFFFF) && (AudioSeq_GetActiveSeqId(4) == 0xFFFF)) {
                Audio_PlayAmbience(9);
            }
            D_801CEFE0 = 1;
        } else {
            Audio_StartObjSoundFanfare(1, NULL, D_801F4C19, 0);
            if (AudioSeq_GetActiveSeqId(0) != 0xFFFF) {
                AudioSeq_QueueSeqCmd(0x140000FF);
            }
            D_801F4C1A = 0;
            D_801CF02C = 0;
            D_801CEFE0 = 0;
        }
        D_801F4C19 = 0;
    }
}
