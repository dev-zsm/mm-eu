// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_RisingDebris_Update(Actor* thisx, PlayState* play) {
    EnFall* this = (EnFall*)thisx;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_451)) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_451) &&
            play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_451)]->id == 2) {
            EnFall_RisingDebris_UpdateEffects(this);
            EnFall_RisingDebris_InitializeEffect(this);
        } else if (this->activeDebrisEffectCount != 0) {
            EnFall_RisingDebris_ResetEffects(this);
        }
    } else if (thisx->home.rot.x != 0) {
        EnFall_RisingDebris_UpdateEffects(this);
        EnFall_RisingDebris_InitializeEffect(this);
    }
}
