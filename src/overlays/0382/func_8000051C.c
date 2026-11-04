// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char03.h"

void DmChar03_Draw(Actor* thisx, PlayState* play) {
    DmChar03* this = (DmChar03*)thisx;

    if (!this->unk_18E) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_136) &&
            (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_136)]->id != 1)) {
            Gfx_SetupDL25_Opa(play->state.gfxCtx);
            SkelAnime_DrawTransformFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
                                           this->skelAnime.dListCount, DmChar03_OverrideLimbDraw, DmChar03_PostLimbDraw,
                                           DmChar03_TransformLimbDraw, &this->actor);
        }
    } else {
        ref_func_80AABA84(play, this);
    }
}
