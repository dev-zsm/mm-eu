// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnTest6* this = (EnTest6*)thisx;
    s32 i;

    if (((SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_INV_SOT_FAST) ||
         (SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_INV_SOT_SLOW) ||
         (SOTCS_GET_OCARINA_MODE(&this->actor) == OCARINA_MODE_APPLY_DOUBLE_SOT)) &&
        (play->playerCsIds[PLAYER_CS_ID_SONG_WARP] == CS_ID_NONE)) {
        Actor_Kill(&this->actor);
        return;
    }

    for (i = 0; i < ARRAY_COUNT(this->lights); i++) {
        Lights_PointNoGlowSetInfo(&this->lights[i].info, this->actor.world.pos.x, (s32)this->actor.world.pos.y - 20,
                                  this->actor.world.pos.z, 255, 255, 180, -1);
        this->lights[i].node = LightContext_InsertLight(play, &play->lightCtx, &this->lights[i].info);
    }

    this->screenFillAlpha = 0;
    this->cueId = SOTCS_CUEID_NONE;
    this->invSoTClockYaw = 0;
    this->drawType = SOTCS_DRAW_TYPE_NONE;

    EnTest6_SetupCutscene(this, play);
    EnTest6_SetupAction(this, EnTest6_StartCutscene);
}
