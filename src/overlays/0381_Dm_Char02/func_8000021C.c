// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char02.h"

void DmChar02_HandleCutscene(DmChar02* this, PlayState* play) {
    u8 changeAnim = true;
    s32 cueChannel;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_131)) {
        cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_131);
        if (play->csCtx.curFrame == play->csCtx.actorCues[cueChannel]->startFrame) {
            switch (play->csCtx.actorCues[cueChannel]->id) {
                default:
                    this->animIndex = DMCHAR02_ANIM_HIT_GROUND;
                    changeAnim = false;
                    break;

                case 1:
                    this->animIndex = DMCHAR02_ANIM_HIT_GROUND;
                    break;

                case 2:
                    this->animIndex = DMCHAR02_ANIM_TURN_AROUND;
                    break;

                case 4:
                    this->animIndex = DMCHAR02_ANIM_FALL;
                    break;
            }

            if (changeAnim) {
                DmChar02_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
            }
        }

        Cutscene_ActorTranslateAndYaw(&this->actor, play, cueChannel);
    }

    if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
        if (this->animIndex == DMCHAR02_ANIM_TURN_AROUND) {
            this->animIndex++;
            DmChar02_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
        }
    }
}
