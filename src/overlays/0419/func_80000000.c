// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ctower_gear.h"

void BgCtowerGear_Splash(BgCtowerGear* this, PlayState* play) {
    s32 i;
    s32 flag40 = this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME;
    Vec3f splashSpawnPos;
    Vec3f splashOffset;
    s32 pad;
    s32 j;
    s16 rotZ = this->dyna.actor.shape.rot.z & 0x1FFF;

    if (flag40 && (rotZ < 0x1B58) && (rotZ >= 0x1388)) {
        Matrix_RotateYS(this->dyna.actor.home.rot.y, MTXMODE_NEW);
        Matrix_RotateXS(this->dyna.actor.home.rot.x, MTXMODE_APPLY);
        Matrix_RotateZS(this->dyna.actor.home.rot.z, MTXMODE_APPLY);
        for (i = 0; i < 4; i++) {
            if (Rand_Next() >= 0x40000000) {
                splashOffset.x = sExitSplashOffsets[i].x - (Rand_ZeroOne() * 30.0f);
                splashOffset.y = sExitSplashOffsets[i].y;
                splashOffset.z = sExitSplashOffsets[i].z;
                Matrix_MultVec3f(&splashOffset, &splashSpawnPos);
                splashSpawnPos.x += this->dyna.actor.world.pos.x + ((Rand_ZeroOne() * 20.0f) - 10.0f);
                splashSpawnPos.y += this->dyna.actor.world.pos.y;
                splashSpawnPos.z += this->dyna.actor.world.pos.z + ((Rand_ZeroOne() * 20.0f) - 10.0f);
                EffectSsGSplash_Spawn(play, &splashSpawnPos, NULL, NULL, 0, (Rand_Next() >> 25) + 340);
            }
        }
    }
    if ((rotZ < 0x1F4) && (rotZ >= 0)) {
        if (flag40) {
            Matrix_RotateYS(this->dyna.actor.home.rot.y, MTXMODE_NEW);
            Matrix_RotateXS(this->dyna.actor.home.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(this->dyna.actor.home.rot.z, MTXMODE_APPLY);
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 2; j++) {
                    splashOffset.x = sEnterSplashOffsets[i].x + (Rand_ZeroOne() * 10.0f);
                    splashOffset.y = sEnterSplashOffsets[i].y;
                    splashOffset.z = sEnterSplashOffsets[i].z;
                    Matrix_MultVec3f(&splashOffset, &splashSpawnPos);
                    splashSpawnPos.x += this->dyna.actor.world.pos.x + ((Rand_ZeroOne() * 20.0f) - 10.0f);
                    splashSpawnPos.y += this->dyna.actor.world.pos.y;
                    splashSpawnPos.z += this->dyna.actor.world.pos.z + ((Rand_ZeroOne() * 20.0f) - 10.0f);
                    EffectSsGSplash_Spawn(play, &splashSpawnPos, NULL, NULL, 0, (Rand_Next() >> 25) + 280);
                }
            }
        }
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WATERWHEEL_LEVEL);
    }
}
