// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioThread_ScheduleProcessCmds();                            /* extern */
M2C_UNK AudioOcarina_Update();                            /* extern */
M2C_UNK AudioOcarina_SetCustomSequence();                            /* extern */
M2C_UNK AudioSfx_ProcessSfxSettings();                            /* extern */
M2C_UNK Audio_UpdateSfxVolumeTransition();                            /* extern */
M2C_UNK Audio_StepFreqLerp(M2C_UNK *);                   /* extern */
M2C_UNK Audio_UpdateRiverSoundVolumes();                            /* extern */
M2C_UNK Audio_UpdateObjSoundProperties();                            /* extern */
M2C_UNK Audio_UpdateObjSoundFanfare();                            /* extern */
M2C_UNK Audio_UpdateSubBgmAtPos();                            /* extern */
M2C_UNK Audio_UpdateSequenceAtPos();                            /* extern */
M2C_UNK Audio_UpdateSceneSequenceResumePoint();                            /* extern */
M2C_UNK Audio_UpdateFanfare();                            /* extern */
M2C_UNK Audio_UpdatePauseState();                            /* extern */
M2C_UNK Audio_ResetRequestedSceneSeqId();                            /* extern */
M2C_UNK AudioVoice_Update();                            /* extern */
M2C_UNK AudioSfx_ProcessRequests();                            /* extern */
M2C_UNK AudioSfx_ProcessActiveSfx();                            /* extern */
M2C_UNK AudioSeq_ProcessSeqCmds();                            /* extern */
M2C_UNK AudioSeq_UpdateActiveSequences();                            /* extern */
s32 AudioSeq_UpdateAudioHeapReset();                                /* extern */
s32 AudioSeq_ResetReverb();                                /* extern */
extern M2C_UNK D_801F4AA8;
extern M2C_UNK D_801F4AB8;

void Audio_Update(void) {
    if ((AudioSeq_UpdateAudioHeapReset() == 0) && (AudioSeq_ResetReverb() == 0)) {
        AudioOcarina_SetCustomSequence();
        AudioOcarina_Update();
        AudioVoice_Update();
        Audio_StepFreqLerp(&D_801F4AA8);
        Audio_StepFreqLerp(&D_801F4AB8);
        Audio_UpdateRiverSoundVolumes();
        Audio_UpdateSceneSequenceResumePoint();
        Audio_UpdateFanfare();
        Audio_UpdateSfxVolumeTransition();
        Audio_UpdateSubBgmAtPos();
        Audio_UpdateObjSoundFanfare();
        Audio_UpdateSequenceAtPos();
        Audio_UpdatePauseState();
        Audio_UpdateObjSoundProperties();
        Audio_ResetRequestedSceneSeqId();
        AudioSfx_ProcessRequests();
        AudioSeq_ProcessSeqCmds();
        AudioSfx_ProcessActiveSfx();
        AudioSeq_UpdateActiveSequences();
        AudioSfx_ProcessSfxSettings();
        AudioThread_ScheduleProcessCmds();
    }
}
