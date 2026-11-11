// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_IsSmallMemScene(PlayState* play) {
    s16* sceneId;

    for (sceneId = sSmallMemSceneIds; sceneId < sSmallMemSceneIds + ARRAY_COUNT(sSmallMemSceneIds); sceneId++) {
        if (play->sceneId == *sceneId) {
            return true;
        }
    }
    return false;
}
