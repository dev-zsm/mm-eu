// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_fence.h"

void BgKin2Fence_SpawnEyeSparkles(BgKin2Fence* this, PlayState* play, s32 mask) {
    static Color_RGBA8 sPrimColor = { 255, 255, 255, 0 };
    static Color_RGBA8 sEnvColor = { 0, 128, 128, 0 };
    s32 i;
    Vec3f sp58;
    s32 pad[2];

    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);

    for (i = 0; i < 2; i++) {
        Matrix_MultVec3f(&sEyeSparkleSpawnPositions[mask][i], &sp58);
        EffectSsKirakira_SpawnDispersed(play, &sp58, &gZeroVec3f, &gZeroVec3f, &sPrimColor, &sEnvColor, 6000, -10);
    }
}
