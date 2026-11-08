// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_picture.h"

void BgKin2Picture_SpawnDust(BgKin2Picture* this, PlayState* play) {
    f32 offset;
    Vec3f basePos;
    Vec3f pos;
    Vec3f velocity;
    Vec3f accel;
    s32 angle;
    s32 scale;
    s16 scaleStep;
    s32 baseAngle;
    s32 i;

    Matrix_SetTranslateRotateYXZ(this->dyna.actor.world.pos.x,
                                 this->dyna.actor.world.pos.y +
                                     (this->dyna.actor.shape.yOffset * this->dyna.actor.scale.y),
                                 this->dyna.actor.world.pos.z, &this->dyna.actor.shape.rot);
    Matrix_MultVec3f(&sDustBasePos, &basePos);
    pos.y = basePos.y - 7.0f;
    velocity.y = 0.0f;
    accel.y = 0.2f;

    for (i = 0, baseAngle = 0; i < DUST_COUNT; i++, baseAngle += (0x10000 / DUST_COUNT)) {
        angle = (s32)(Rand_ZeroOne() * (0x10000 / DUST_COUNT)) + baseAngle;
        offset = (Rand_ZeroOne() * 14.0f) + 4.0f;
        pos.x = Math_SinS(angle) * offset;
        pos.z = Math_CosS(angle) * offset;
        velocity.x = (Rand_ZeroOne() - 0.5f) + (pos.x * (1.0f / 6.0f));
        velocity.z = (Rand_ZeroOne() - 0.5f) + (pos.z * (1.0f / 6.0f));
        pos.x += basePos.x;
        pos.z += basePos.z;
        accel.x = velocity.x * -0.09f;
        accel.z = velocity.z * -0.09f;
        scale = (s32)(Rand_ZeroOne() * 10.0f) + 10;
        scaleStep = (s32)(Rand_ZeroOne() * 10.0f) + 15;
        ref_func_800B1210(play, &pos, &velocity, &accel, scale, scaleStep);
    }
}
