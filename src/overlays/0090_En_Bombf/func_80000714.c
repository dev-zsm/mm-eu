// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bombf.h"

void ref_func_808AEFD4(EnBombf* this, PlayState* play) {
    if (this->colliderJntSph.elements[0].dim.modelSphere.radius == 0) {
        this->actor.flags |= ACTOR_FLAG_DRAW_CULLING_DISABLED;
        Rumble_Request(this->actor.xzDistToPlayer, 255, 20, 150);
    }

    this->colliderJntSph.elements[0].dim.modelSphere.radius = 100;
    this->colliderJntSph.elements[0].dim.worldSphere.radius = 100;

    if (ENBOMBF_GET(&this->actor) == ENBOMBF_1) {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->colliderJntSph.base);
    }

    if (play->envCtx.adjLightSettings.light1Color[0] != 0) {
        play->envCtx.adjLightSettings.light1Color[0] -= 25;
    }

    if (play->envCtx.adjLightSettings.light1Color[1] != 0) {
        play->envCtx.adjLightSettings.light1Color[1] -= 25;
    }

    if (play->envCtx.adjLightSettings.light1Color[2] != 0) {
        play->envCtx.adjLightSettings.light1Color[2] -= 25;
    }

    if (play->envCtx.adjLightSettings.ambientColor[0] != 0) {
        play->envCtx.adjLightSettings.ambientColor[0] -= 25;
    }

    if (play->envCtx.adjLightSettings.ambientColor[1] != 0) {
        play->envCtx.adjLightSettings.ambientColor[1] -= 25;
    }

    if (play->envCtx.adjLightSettings.ambientColor[2] != 0) {
        play->envCtx.adjLightSettings.ambientColor[2] -= 25;
    }

    if (this->timer == 0) {
        Player* player = GET_PLAYER(play);

        if ((player->stateFlags1 & PLAYER_STATE1_CARRYING_ACTOR) && (&this->actor == player->heldActor)) {
            player->actor.child = NULL;
            player->heldActor = NULL;
            player->interactRangeActor = NULL;
            player->stateFlags1 &= ~PLAYER_STATE1_CARRYING_ACTOR;
        }
        Actor_Kill(&this->actor);
    }
}
