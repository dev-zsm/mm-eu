// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dkjail_ivy.h"

void BgDkjailIvy_IvyCutEffects(BgDkjailIvy* this, PlayState* play) {
    static Gfx* sLeafDlists[] = { gKakeraLeafMiddleDL, gKakeraLeafTipDL };
    static s16 sLeafScales[] = { 110, 80, 60, 40 };
    f32 phi_fs0;
    s32 i;
    Vec3f spD4;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s16 angle;

    Matrix_RotateYS(this->dyna.actor.home.rot.y, MTXMODE_NEW);

    for (i = 0, angle = 0; i < 50; i++, angle += 0x4E20) {
        spD4.y = (i * (90.0f / 49.0f)) + 2.0f;
        if (spD4.y < 45.0f) {
            phi_fs0 = ((1.0f / 180.0f) * spD4.y) + 0.75f;
        } else if (spD4.y < 90.0f) {
            phi_fs0 = ((-1.0f / 180.0f) * spD4.y) + 1.25f;
        } else {
            phi_fs0 = ((-1.0f / 30.0f) * spD4.y) + 3.75f;
        }

        spD4.x = Math_SinS(angle) * 40.0f * phi_fs0;
        spD4.z = (Rand_ZeroOne() * 6.0f) - 3.0f;

        Matrix_MultVec3f(&spD4, &pos);

        velocity.x = (Rand_ZeroOne() - 0.5f) + (pos.x * 0.075f);
        velocity.y = 2.0f * Rand_ZeroOne();
        velocity.z = (Rand_ZeroOne() - 0.5f) + (pos.z * 0.075f);

        pos.x += this->dyna.actor.world.pos.x;
        pos.y += this->dyna.actor.world.pos.y;
        pos.z += this->dyna.actor.world.pos.z;

        EffectSsKakera_Spawn(play, &pos, &velocity, &pos, -0x82, 0x40, 0x28, 0, 0, sLeafScales[i & 3], 0, 0, 44, -1,
                             GAMEPLAY_KEEP, sLeafDlists[(s32)Rand_Next() > 0]);

        if ((i > 20) && ((i % 2) != 0)) {
            accel.x = (Rand_ZeroOne() - 0.5f) * 0.2f;
            accel.y = (Rand_ZeroOne() * 0.02f) - 0.1f;
            accel.z = (Rand_ZeroOne() - 0.5f) * 0.2f;

            ref_func_800B12F0(play, &pos, &gZeroVec3f, &accel, ((Rand_Next() >> 26) + 10), (Rand_Next() >> 28), 50);
        }
    }
}
