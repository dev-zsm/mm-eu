// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_astr_bombwall.h"

void BgAstrBombwall_SpawnFragments(BgAstrBombwall* this, PlayState* play) {
    s32 i;
    Vec3f vec;
    Vec3f pos;
    s16 spinRate;
    Vec3f velocity;
    f32 rand;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
    for (i = 0; i < 30; i++) {
        vec.x = Rand_Centered() * 140.0f;
        vec.y = Rand_ZeroOne() * 200.0f;
        vec.z = 0.0f;
        Matrix_MultVec3f(&vec, &pos);
        Math_Vec3f_Sum(&this->dyna.actor.world.pos, &pos, &pos);
        ref_func_800BBFB0(play, &pos, 50.0f, 2, Rand_ZeroOne() * 120.0f + 20.0f, Rand_ZeroOne() * 240.0f + 20.0f, 0);
        velocity.x = Rand_ZeroOne() * 2.5f;
        velocity.y = (Rand_ZeroOne() * 2.5f) + 1.0f;
        velocity.z = Rand_ZeroOne() * 2.5f;
        rand = Rand_ZeroOne();

        if (rand < 0.2f) {
            spinRate = 0x60;
        } else if (rand < 0.6f) {
            spinRate = 0x40;
        } else {
            spinRate = 0x20;
        }
        EffectSsKakera_Spawn(play, &pos, &velocity, &pos, -260, spinRate, 20, 0, 0, 10, 0, 0, 50, -1, OBJECT_ASTR_OBJ,
                             gAstralObservatoryBombWallFragmentDL);
    }
}
