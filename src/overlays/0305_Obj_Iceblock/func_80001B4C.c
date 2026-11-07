// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A24BDC(ObjIceblock* this, PlayState* play, f32 arg2, f32 arg3, s32 arg4) {
    s32 i;
    Vec3f sp88;
    f32 temp_f20;
    s16 temp_f22;
    s16 phi_s0;
    s32 phi_s1 = 0;

    if (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        sp88.y = this->unk_244;
        temp_f22 = 0x10000 / arg4;

        for (i = 0, phi_s0 = 0; i < arg4; i++, phi_s0 += temp_f22) {
            temp_f20 = ((Rand_ZeroOne() * 5.0f) + 40.0f) * arg2;
            sp88.x = this->dyna.actor.world.pos.x + (Math_SinS((s32)(Rand_ZeroOne() * temp_f22) + phi_s0) * temp_f20);
            sp88.z = this->dyna.actor.world.pos.z + (Math_CosS((s32)(Rand_ZeroOne() * temp_f22) + phi_s0) * temp_f20);
            EffectSsGSplash_Spawn(play, &sp88, NULL, NULL, 0, ((Rand_ZeroOne() * 60.0f) + 320.0f) * arg3);
        }
    }
}
