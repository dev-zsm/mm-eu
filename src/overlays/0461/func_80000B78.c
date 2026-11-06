// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B14CF8(PlayState* play, Vec3f vec, s16 arg2, s16 arg3, s32 arg4) {
    static Color_RGBA8 sPrimColor = { 170, 130, 90, 255 };
    static Color_RGBA8 sEnvColor = { 100, 60, 20, 0 };
    s32 i;
    s16 temp_s0;
    Vec3f pos;
    Vec3f velocity = { 0.0f, 0.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    f32 temp_f20;
    f32 temp_f22;

    for (i = 0; i < arg4; i++) {
        temp_f20 = Rand_ZeroOne() * 30.0f;
        temp_f22 = Rand_ZeroOne() * 1.5f;
        temp_s0 = Rand_Next();

        pos.x = (Math_SinS(temp_s0) * temp_f20) + vec.x;
        pos.y = (Rand_Centered() * 4.0f) + vec.y;
        pos.z = (Math_CosS(temp_s0) * temp_f20) + vec.z;

        velocity.x += temp_f22 * Math_SinS(temp_s0);
        velocity.y += Rand_Centered() + 0.5f;
        velocity.z += temp_f22 * Math_CosS(temp_s0);

        accel.x = -0.1f * velocity.x;
        accel.y = -0.1f * velocity.y;
        accel.z = -0.1f * velocity.z;

        ref_func_800B0EB0(play, &pos, &velocity, &accel, &sPrimColor, &sEnvColor, arg2, arg3, 10);
    }
}
