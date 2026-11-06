// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_ArriveCsPart1(EnTest7* this, PlayState* play) {
    f32 lerp = (40 - this->timer) / (f32)(40 - 0);
    Camera* subCam;

    this->flags |= OWL_WARP_FLAGS_DRAW_LENS_FLARE;

    this->windCapsule.unk_00 = 11.0f;
    this->windCapsule.xzScale = 0.05f;
    this->windCapsule.yScale = 0.05f;
    this->windCapsule.yaw += 0x2EE0;

    this->actor.world.pos.x = LERPIMP_ALT(this->actor.home.pos.x, this->actor.world.pos.x, lerp);
    this->actor.world.pos.y = LERPIMP_ALT(this->actor.home.pos.y, this->actor.world.pos.y, lerp);
    this->actor.world.pos.z = LERPIMP_ALT(this->actor.home.pos.z, this->actor.world.pos.z, lerp);

    subCam = Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));
    EnTest7_UpdateSubCamArrivalCs2(this, play, &this->actor.home.pos, lerp);

    subCam->at.x = this->actor.world.pos.x;
    subCam->at.y = this->actor.world.pos.y + 40.0f;
    subCam->at.z = this->actor.world.pos.z;

    Actor_PlaySfx_Flagged(&this->actor, NA_SE_PL_WARP_WING_ROLL_2 - SFX_FLAG);
    if (this->timer >= 40) {
        this->flags &= ~OWL_WARP_FLAGS_DRAW_LENS_FLARE;
        EnTest7_SetupAction(this, EnTest7_ArriveCsPart2);
    }
}
