// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_WarpCsPart3(EnTest7* this, PlayState* play) {
    Vec3f featherPos;
    Camera* subCam;
    f32 randLerp;

    EnTest7_UpdateGrowingWindCapsule(this, play);

    if (Rand_ZeroOne() < 0.3f) {
        subCam = Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));
        randLerp = Rand_ZeroOne();

        featherPos.x = LERPIMP_ALT(this->actor.world.pos.x, subCam->eye.x, randLerp);
        featherPos.y = LERPIMP_ALT(this->actor.world.pos.y, subCam->eye.y, randLerp);
        featherPos.z = LERPIMP_ALT(this->actor.world.pos.z, subCam->eye.z, randLerp);

        EnTest7_AddAndChooseFeather(this->feathers, &featherPos, true);
    }

    Math_Vec3f_Copy(&featherPos, &this->actor.world.pos);
    EnTest7_AddAndChooseFeather(this->feathers, &featherPos, true);
    this->jointTable[1].y += 0x2EE0;
}
