// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void DmChar05_Update(Actor* thisx, PlayState* play) {
    DmChar05* this = (DmChar05*)thisx;

    ref_func_80AACF04(this, play);
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_109)) {
        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_109)]->id == 3) {
            SkelAnime_Update(&this->skelAnime);
        }
    } else if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_473)) {
        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_473)]->id == 3) {
            SkelAnime_Update(&this->skelAnime);
        }
    } else if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_518)) {
        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_518)]->id == 2) {
            SkelAnime_Update(&this->skelAnime);
        }
    } else if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_559)) {
        if ((play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_559)]->id == 2) ||
            (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_559)]->id == 3)) {
            SkelAnime_Update(&this->skelAnime);
        }

        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_559)]->id == 4) {
            this->actor.world.rot.y += 0x258;
            this->actor.shape.rot.y += 0x258;
        }
    }
    this->actionFunc(this, play);
    ref_func_80AAD4A8(this, play);
}
