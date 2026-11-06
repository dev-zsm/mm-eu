// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char03.h"

void ref_func_80AAB710(DmChar03* this, PlayState* play) {
    u8 changeAnim = true;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_136)) {
        s32 cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_136);

        if (play->csCtx.curFrame == play->csCtx.actorCues[cueChannel]->startFrame) {
            switch (play->csCtx.actorCues[cueChannel]->id) {
                case 1:
                    changeAnim = false;
                    break;

                case 2:
                    this->animIndex = DMCHAR03_ANIM_FALL_OVER;
                    break;

                case 3:
                    this->unk_18E = false;
                    changeAnim = false;
                    Actor_Kill(&this->actor);
                    break;

                case 4:
                    Item_Give(play, ITEM_MASK_DEKU);
                    changeAnim = false;
                    this->actionFunc = ref_func_80AAB5F8;
                    break;

                default:
                    changeAnim = false;
                    break;
            }

            if (changeAnim) {
                DmChar03_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
            }
        }
        Cutscene_ActorTranslateAndYaw(&this->actor, play, cueChannel);
    }
}
