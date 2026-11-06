// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AADB4C(Actor* thisx, PlayState* play) {
    DmChar05* this = (DmChar05*)thisx;

    if (this->unk_18E == 0) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_518) &&
            (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_518)]->id != 1)) {
            Gfx_SetupDL25_Opa(play->state.gfxCtx);
            SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable,
                                  this->skelAnime.dListCount, NULL, NULL, &this->actor);
        }
    } else if (this->unk_18E == 1) {
        ref_func_80AADF54(play, this);
    }
}
