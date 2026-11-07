// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_WarpCsPart2(EnTest7* this, PlayState* play) {
    Vec3f featherPos;

    if (Keyframe_UpdateFlex(&this->kfSkelAnime)) {
        EnTest7_SetupAction(this, EnTest7_WarpCsPart3);
    }

    if (this->kfSkelAnime.frameCtrl.curTime > 60.0f) {
        EnTest7_UpdateGrowingWindCapsule(this, play);
    }

    if ((this->kfSkelAnime.frameCtrl.curTime > 20.0f) && !(this->flags & OWL_WARP_FLAGS_40)) {
        this->flags |= OWL_WARP_FLAGS_40;
        Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_PL_WARP_WING_CLOSE);
    }

    if (this->kfSkelAnime.frameCtrl.curTime > 42.0f) {
        if (!(this->flags & OWL_WARP_FLAGS_80)) {
            this->flags |= OWL_WARP_FLAGS_80;
            Audio_PlaySfx_AtPos(&this->actor.projectedPos, NA_SE_PL_WARP_WING_ROLL);
        }

        if (Rand_ZeroOne() < 0.3f) {
            Camera* subCam =
                Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));
            f32 randLerp = Rand_ZeroOne();

            featherPos.x = LERPIMP_ALT(this->actor.world.pos.x, subCam->eye.x, randLerp);
            featherPos.y = LERPIMP_ALT(this->actor.world.pos.y, subCam->eye.y, randLerp);
            featherPos.z = LERPIMP_ALT(this->actor.world.pos.z, subCam->eye.z, randLerp);

            EnTest7_AddAndChooseFeather(this->feathers, &featherPos, true);
            this->flags |= OWL_WARP_FLAGS_8;
        }
    } else {
        this->flags |= OWL_WARP_FLAGS_DRAW_WINGS;
    }
}
