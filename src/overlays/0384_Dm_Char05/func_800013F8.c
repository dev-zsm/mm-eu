// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AAD998(Actor* thisx, PlayState* play) {
    DmChar05* this = (DmChar05*)thisx;
    s32 pad[2];

    if (this->unk_18E == 0) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_109) &&
            (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_109)]->id != 1)) {
            OPEN_DISPS(play->state.gfxCtx);

            Gfx_SetupDL25_Opa(play->state.gfxCtx);
            POLY_OPA_DISP = Gfx_SetFog(POLY_OPA_DISP, this->unk_19C, this->unk_1A0, this->unk_1A4, this->unk_1A8,
                                       this->unk_1AC, this->unk_1B0);
            SkelAnime_DrawOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, DmChar05_OverrideLimbDraw,
                              DmChar05_PostLimbDraw, &this->actor);

            CLOSE_DISPS(play->state.gfxCtx);
        }
    } else if (this->unk_18E == 1) {
        ref_func_80AADD9C(play, this);
    }
}
