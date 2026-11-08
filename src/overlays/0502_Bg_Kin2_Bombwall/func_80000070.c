// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_bombwall.h"

void BgKin2Bombwall_SpawnEffects(BgKin2Bombwall* this, PlayState* play) {
    s32 i;
    Vec3f pos;
    Vec3f velocity;
    Vec3f spD8;
    Vec3f spCC;
    s32 j;
    s32 k;
    f32 temp_a0;
    s32 pad;
    s16 phi_s0;
    s16 phi_s1;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);

    for (i = 0, k = 0; i < 6; i++) {
        temp_a0 = (i + 1) * 15.f;
        for (j = 0; j < ARRAY_COUNT(sRandomYOffsets); j++) {
            k++;
            k &= 7;

            spD8.x = sRandomYOffsets[j] + (s32)(Rand_Next() >> 0x1C);
            spD8.y = ((Rand_ZeroOne() - 0.5f) * 15.0f) + temp_a0;
            spD8.z = (Rand_ZeroOne() * 20.0f) - 10.0f;

            spCC.x = (2.0f * (Rand_ZeroOne() - 0.5f)) + (spD8.x * (6.0f / 325.0f));
            spCC.y = (Rand_ZeroOne() * 7.0f) + 4.0f;
            spCC.z = spD8.z * 0.3f;

            Matrix_MultVec3f(&spD8, &pos);
            Matrix_MultVec3f(&spCC, &velocity);

            pos.x += this->dyna.actor.world.pos.x;
            pos.y += this->dyna.actor.world.pos.y;
            pos.z += this->dyna.actor.world.pos.z;

            if (Rand_Next() % 4 == 0) {
                phi_s0 = 0x20;
            } else {
                phi_s0 = 0x40;
            }

            if (k < 2 || (s32)Rand_Next() > 0) {
                phi_s0 |= 1;
                phi_s1 = 1;
                ref_func_800B0E48(play, &pos, &gZeroVec3f, &sDustAccel, &sPrimColor, &sEnvColor, (Rand_Next() >> 0x1B) + 70,
                              (Rand_Next() >> 0x1A) + 60); 
            } else {
                phi_s1 = 0;
            }
            EffectSsKakera_Spawn(play, &pos, &velocity, &pos, -550, phi_s0, 30, 0, 0, sScales[k], phi_s1, 0, 50, -1,
                                 OBJECT_KIN2_OBJ, gOceanSpiderHouseBombableWallDebrisDL);
        }
    }
}
