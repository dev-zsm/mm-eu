// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_kankyo.h"

void Environment_PlaySceneSequence(PlayState* play) {
    u8 dayMinusOne = ((void)0, gSaveContext.save.day) - 1;

    if (dayMinusOne >= 3) {
        dayMinusOne = 0;
    }

    if (play->envCtx.timeSeqState != TIMESEQ_REQUEST) {
        play->envCtx.timeSeqState = TIMESEQ_DISABLED;
        if (((void)0, gSaveContext.forcedSeqId) != NA_BGM_GENERAL_SFX) {
            play->envCtx.timeSeqState = TIMESEQ_REQUEST;
            SEQCMD_PLAY_SEQUENCE(SEQ_PLAYER_BGM_MAIN, 0, ((void)0, gSaveContext.forcedSeqId) + SEQ_FLAG_ASYNC);
            gSaveContext.forcedSeqId = NA_BGM_GENERAL_SFX;
        } else if (!Environment_IsFinalHours(play) || ref_func_800FE5D0(play) ||
                   (AudioSeq_GetActiveSeqId(SEQ_PLAYER_BGM_MAIN) != NA_BGM_FINAL_HOURS)) {
            if (play->sceneSequences.seqId == NA_BGM_NO_MUSIC) {
                if (play->sceneSequences.ambienceId == AMBIENCE_ID_13) {
                    return;
                }
                if (play->sceneSequences.ambienceId != ((void)0, gSaveContext.ambienceId)) {
                    Audio_PlayAmbience(play->sceneSequences.ambienceId);
                }
            } else if (play->sceneSequences.ambienceId == AMBIENCE_ID_13) {
                if (play->sceneSequences.seqId != ((void)0, gSaveContext.seqId)) {
                    Audio_PlaySceneSequence(play->sceneSequences.seqId, dayMinusOne);
                }
            } else if ((CURRENT_TIME >= CLOCK_TIME(6, 0)) && (CURRENT_TIME <= CLOCK_TIME(17, 10))) {
                if (gSceneSeqState != SCENESEQ_DEFAULT) {
                    Audio_PlayMorningSceneSequence(play->sceneSequences.seqId, dayMinusOne);
                } else if ((CURRENT_TIME >= CLOCK_TIME(6, 1)) &&
                           (play->sceneSequences.seqId != ((void)0, gSaveContext.seqId))) {
                    Audio_PlaySceneSequence(play->sceneSequences.seqId, dayMinusOne);
                }
                play->envCtx.timeSeqState = TIMESEQ_FADE_DAY_BGM;
            } else {
                if (play->sceneSequences.ambienceId != ((void)0, gSaveContext.ambienceId)) {
                    Audio_PlayAmbience(play->sceneSequences.ambienceId);
                }
                if ((CURRENT_TIME > CLOCK_TIME(17, 10)) && (CURRENT_TIME < CLOCK_TIME(19, 0))) {
                    play->envCtx.timeSeqState = TIMESEQ_EARLY_NIGHT_CRITTERS;
                } else if ((CURRENT_TIME > CLOCK_TIME(19, 0)) || (CURRENT_TIME < CLOCK_TIME(5, 0))) {
                    play->envCtx.timeSeqState = TIMESEQ_NIGHT_CRITTERS;
                } else {
                    play->envCtx.timeSeqState = TIMESEQ_MORNING_CRITTERS;
                }
            }
        }
        Audio_SetEnvReverb(play->roomCtx.curRoom.echo);
        gSceneSeqState = SCENESEQ_DEFAULT;
    }
}
