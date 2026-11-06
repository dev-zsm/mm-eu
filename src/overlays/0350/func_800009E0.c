// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5BB40(EnKusa2* this, PlayState* play, s32 arg2) {
    static Vec3f ref_D_80A5EB0C = { 0.0f, 0.3f, 0.0f };
    static Vec3f ref_D_80A5EB18 = { 0.0f, 0.0f, 0.0f };
    s32 pad;
    s32 i;
    Vec3f sp84;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s16 temp_s0;

    if (this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        for (i = 0; i <= arg2; i++) {
            temp_s0 = Rand_S16Offset(-16000, 32000) + this->actor.world.rot.y;
            temp_f20 = Math_SinS(temp_s0);
            temp_f22 = Math_CosS(temp_s0);
            temp_f24 = Rand_ZeroOne() * -12.0f;

            sp84.x = (temp_f20 * temp_f24) + this->actor.world.pos.x;
            sp84.y = (Rand_ZeroOne() * 8.0f) + 2.0f + this->actor.world.pos.y;
            sp84.z = (temp_f22 * temp_f24) + this->actor.world.pos.z;

            ref_D_80A5EB18.x = temp_f20 * -0.9f;
            ref_D_80A5EB18.z = temp_f22 * -0.9f;

            ref_D_80A5EB0C.x = ref_D_80A5EB18.x * -0.09f;
            ref_D_80A5EB0C.z = ref_D_80A5EB18.z * -0.09f;

            ref_func_800B1210(play, &sp84, &ref_D_80A5EB18, &ref_D_80A5EB0C, 10, 50);
        }
    }
}
