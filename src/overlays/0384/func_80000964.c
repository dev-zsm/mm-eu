// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AACF04(DmChar05* this, PlayState* play) {
    u8 changeAnim = true;
    s32 cueChannel;

    switch (DMCHAR05_GET(&this->actor)) {
        case DMCHAR05_0:
            if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_109)) {
                cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_109);

                if (play->csCtx.curFrame == play->csCtx.actorCues[cueChannel]->startFrame) {
                    switch (play->csCtx.actorCues[cueChannel]->id) {
                        case 1:
                            changeAnim = false;
                            break;

                        case 2:
                            this->unk_1B4 = 1;
                            break;

                        case 3:
                            this->animIndex = DMCHAR05_ANIM_0;
                            break;

                        case 4:
                            Item_Give(play, ITEM_MASK_GORON);
                            changeAnim = false;
                            this->actionFunc = ref_func_80AAC990;
                            break;

                        case 5:
                            changeAnim = false;
                            Actor_Kill(&this->actor);
                            break;

                        default:
                            changeAnim = false;
                            break;
                    }

                    if (changeAnim) {
                        DmChar05_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
                    }
                }

                Cutscene_ActorTranslateAndYaw(&this->actor, play, cueChannel);
            }
            break;

        case DMCHAR05_1:
            if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_473)) {
                cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_473);

                if (play->csCtx.curFrame == play->csCtx.actorCues[cueChannel]->startFrame) {
                    switch (play->csCtx.actorCues[cueChannel]->id) {
                        case 1:
                            changeAnim = false;
                            break;

                        case 2:
                            this->animIndex = DMCHAR05_ANIM_1;
                            this->unk_1B4 = 1;
                            break;

                        case 3:
                            this->animIndex = DMCHAR05_ANIM_1;
                            break;

                        case 4:
                            Item_Give(play, ITEM_MASK_ZORA);
                            changeAnim = false;
                            this->actionFunc = ref_func_80AACD1C;
                            break;

                        case 5:
                            changeAnim = false;
                            Actor_Kill(&this->actor);
                            break;

                        default:
                            changeAnim = false;
                            break;
                    }

                    if (changeAnim) {
                        DmChar05_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
                    }
                }

                Cutscene_ActorTranslateAndYaw(&this->actor, play, cueChannel);
            }
            break;

        case DMCHAR05_2:
            if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_518)) {
                cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_518);

                if (play->csCtx.curFrame == play->csCtx.actorCues[cueChannel]->startFrame) {
                    switch (play->csCtx.actorCues[cueChannel]->id) {
                        case 1:
                            changeAnim = false;
                            break;

                        case 2:
                            this->animIndex = DMCHAR05_ANIM_3;
                            break;

                        case 3:
                            this->animIndex = DMCHAR05_ANIM_2;
                            break;

                        case 4:
                            Item_Give(play, ITEM_MASK_GIBDO);
                            changeAnim = false;
                            this->actionFunc = ref_func_80AACE10;
                            break;

                        case 5:
                            changeAnim = false;
                            Actor_Kill(&this->actor);
                            break;

                        default:
                            changeAnim = false;
                            break;
                    }

                    if (changeAnim) {
                        DmChar05_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
                    }
                }

                Cutscene_ActorTranslateAndYaw(&this->actor, play, cueChannel);
            }
            break;

        case DMCHAR05_3:
            if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_559)) {
                cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_559);

                if (play->csCtx.curFrame == play->csCtx.actorCues[cueChannel]->startFrame) {
                    switch (play->csCtx.actorCues[cueChannel]->id) {
                        default:
                            changeAnim = false;
                            break;

                        case 1:
                            changeAnim = false;
                            break;

                        case 2:
                            this->animIndex = DMCHAR05_ANIM_4;
                            break;

                        case 3:
                            this->animIndex = DMCHAR05_ANIM_5;
                            break;

                        case 4:
                            this->animIndex = DMCHAR05_ANIM_5;
                            break;
                    }

                    if (changeAnim) {
                        DmChar05_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
                    }
                }

                if (play->csCtx.actorCues[cueChannel]->id != 4) {
                    Cutscene_ActorTranslateAndYaw(&this->actor, play, cueChannel);
                } else {
                    Cutscene_ActorTranslate(&this->actor, play, cueChannel);
                }
            }

            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                if (this->animIndex == DMCHAR05_ANIM_4) {
                    this->animIndex++;
                    DmChar05_ChangeAnim(&this->skelAnime, &sAnimationInfo[this->animIndex], 0);
                }
            }
            break;
    }
}
