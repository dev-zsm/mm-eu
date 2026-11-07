// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_AddFeather(OwlWarpFeather* feather, Vec3f* pos, s32 isPosYRand) {
    s16 yaw = Rand_ZeroOne() * 0xFFFF;
    f32 velocityXZ;

    feather->pos = *pos;

    if (isPosYRand) {
        feather->pos.x += Math_CosS(yaw) * 0.0f;
        feather->pos.y += (Rand_ZeroOne() * 100.0f) - 20.0f;
        feather->pos.z += Math_SinS(yaw) * 0.0f;
    }

    velocityXZ = (Rand_ZeroOne() * 4.0f) + 2.0f;

    feather->velocity.x = Math_CosS(yaw) * velocityXZ;
    feather->velocity.y = Rand_ZeroOne();
    feather->velocity.z = Math_SinS(yaw) * velocityXZ;

    feather->accel.x = 0.0f;
    feather->accel.y = 0.0f;
    feather->accel.z = 0.0f;

    feather->scale = 0.25f;
    feather->rot.x = Rand_ZeroOne() * 0x10000;
    feather->rot.y = Rand_ZeroOne() * 0x10000;
    feather->rot.z = Rand_ZeroOne() * 0x10000;
    feather->unk_04 = 60;

    if (Rand_ZeroOne() < 0.9f) {
        feather->type = OWL_WARP_FEATHER_TYPE_1;
        feather->rot.x = Rand_ZeroOne() * 0x10000;
        feather->rot.y = Rand_ZeroOne() * 0x10000;
        feather->rot.z = Rand_ZeroOne() * 0x10000;
        feather->angularVelocity.x = 0;
        feather->angularVelocity.y = 0;
        feather->angularVelocity.z = 0;
    } else {
        feather->type = OWL_WARP_FEATHER_TYPE_2;
        feather->rot.x = 0;
        feather->rot.y = 0;
        feather->rot.z = Rand_ZeroOne() * 5000.0f;
        feather->angularVelocity.x = 0;
        feather->angularVelocity.y = (Rand_ZeroOne() * 8000.0f) + 2000.0f;
        if (Rand_ZeroOne() > 0.5f) {
            feather->angularVelocity.y = -feather->angularVelocity.y;
        }
        feather->angularVelocity.z = 0;
    }
}
