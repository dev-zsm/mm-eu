// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_UpdateSubCamArrivalCs2(EnTest7* this, PlayState* play, Vec3f* atNext, f32 lerp) {
    Vec3f subCamAt;
    Camera* subCam =
        Play_GetCamera(play, CutsceneManager_GetCurrentSubCamId(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]));

    subCam->focalActor = NULL;

    subCamAt.x = LERPIMP_ALT(atNext->x, subCam->at.x, lerp);
    subCamAt.y = LERPIMP_ALT(atNext->y, subCam->at.y, lerp);
    subCamAt.z = LERPIMP_ALT(atNext->z, subCam->at.z, lerp);

    subCam->at.x = subCamAt.x;
    subCam->at.y = subCamAt.y;
    subCam->at.z = subCamAt.z;
}
