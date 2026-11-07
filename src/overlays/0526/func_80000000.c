// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_jg_gakki.h"

void ObjJgGakki_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    ObjJgGakki* this = (ObjJgGakki*)thisx;
    f32 endFrame = Animation_GetLastFrame(&gGoronElderDrumTakeOutAnim);

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 24.0f);
    SkelAnime_Init(play, &this->skelAnime, &gGoronElderDrumSkel, NULL, NULL, NULL, 0);

    if (((play->sceneId == SCENE_SPOT00) && (gSaveContext.sceneLayer == 7)) && (play->csCtx.scriptIndex == 0)) {
        Animation_Change(&this->skelAnime, &gGoronElderDrumTakeOutAnim, 1.0f, endFrame, endFrame, ANIMMODE_ONCE, 0.0f);
    } else if ((play->sceneId == SCENE_17SETUGEN) || (play->sceneId == SCENE_10YUKIYAMANOMURA)) {
        Animation_Change(&this->skelAnime, &gGoronElderDrumTakeOutAnim, 1.0f, 0.0f, endFrame, ANIMMODE_ONCE, 0.0f);
    } else {
        Actor_Kill(&this->actor);
    }
    Actor_SetScale(&this->actor, 0.01f);
}
