// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char02.h"

void DmChar02_Draw(Actor* thisx, PlayState* play) {
    s32 pad[2];
    DmChar02* this = (DmChar02*)thisx;
    s32 shouldDraw = false;

    if ((play->csCtx.state == CS_STATE_IDLE) && (this->actor.world.pos.y < 100.0f)) {
        shouldDraw = true;
    } else if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_107)) {
        switch (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_107)]->id) {
            case 0x17:
            case 0x1C:
            case 0x26:
                shouldDraw = true;
                break;
        }
    }

    if (shouldDraw) {
        Gfx_SetupDL25_Opa(play->state.gfxCtx);
        SkelAnime_DrawTransformFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
                                       this->skelAnime.dListCount, DmChar02_OverrideLimbDraw, DmChar02_PostLimbDraw,
                                       DmChar02_TransformLimbDraw, &this->actor);
    }
}
