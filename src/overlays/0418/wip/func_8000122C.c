// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_Init), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_osn.h"

void func_8000122C(Actor* thisx, PlayState* play) {
    s32 pad;
    EnOsn* this = (EnOsn*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 20.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gHappyMaskSalesmanSkel, &gHappyMaskSalesmanIdleAnim, NULL, NULL, 0);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&this->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);
    this->alpha = 255;

    switch (ENOSN_GET_TYPE(&this->actor)) {
        case OSN_TYPE_CHOOSE:
            if ((gSaveContext.save.entrance == ENTRANCE(CLOCK_TOWER_INTERIOR, 2)) ||
                (gSaveContext.save.entrance == ENTRANCE(CLOCK_TOWER_INTERIOR, 3)) ||
                (gSaveContext.save.entrance == ENTRANCE(CLOCK_TOWER_INTERIOR, 6))) {
                this->stateFlags |= OSN_STATE_SPECIAL_CONVERSTATION;
            }
            this->shouldRotateHead = true;
            if (play->sceneId == SCENE_INSIDETOWER) {
                if ((gSaveContext.save.entrance == ENTRANCE(CLOCK_TOWER_INTERIOR, 2)) ||
                    (gSaveContext.save.entrance == ENTRANCE(CLOCK_TOWER_INTERIOR, 6))) {
                    this->actionFunc = EnOsn_HandleCutscene;
                } else if (gSaveContext.save.entrance == ENTRANCE(CLOCK_TOWER_INTERIOR, 3)) {
                    EnOsn_InitCutscene(this);
                    this->actionFunc = EnOsn_StartCutscene;
                } else {
                    EnOsn_ChooseAction(this, play);
                }
            } else {
                EnOsn_ChooseAction(this, play);
            }
            break;

        case OSN_TYPE_LIE_FACE_DOWN:
            this->animIndex = OSN_ANIM_LYING_DOWN_FACE_UP;
            Actor_ChangeAnimationByInfo(&this->skelAnime, sAnimationInfo, this->animIndex);
            this->actionFunc = EnOsn_DoNothing;
            break;

        case OSN_TYPE_LIE_FACE_UP:
            this->animIndex = OSN_ANIM_LYING_DOWN_FACE_DOWN;
            Actor_ChangeAnimationByInfo(&this->skelAnime, sAnimationInfo, this->animIndex);
            this->actionFunc = EnOsn_DoNothing;
            break;

        case OSN_TYPE_CUTSCENE:
            this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
            this->actionFunc = EnOsn_HandleCutscene;
            break;

        default:
            Actor_Kill(&this->actor);
            break;
    }
}
