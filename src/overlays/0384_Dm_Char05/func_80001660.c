// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AADC00(Actor* thisx, PlayState* play) {
    s32 pad;
    DmChar05* this = (DmChar05*)thisx;
    s32 cueChannel;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_559)) {
        cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_559);

        if ((play->csCtx.actorCues[cueChannel]->id != 1) && (play->csCtx.actorCues[cueChannel]->id != 4)) {
            Gfx_SetupDL25_Opa(play->state.gfxCtx);
            SkelAnime_DrawOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, DmChar05_OverrideLimbDraw,
                              DmChar05_PostLimbDraw, &this->actor);
        }

        if (play->csCtx.actorCues[cueChannel]->id == 4) {
            Matrix_Translate(-600.0f, 0.0f, 0.0f, MTXMODE_APPLY);
            Gfx_DrawDListOpa(play, object_dmask_DL_001E70);
        }
    }
}
