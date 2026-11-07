// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A2508C(ObjIceblock* this, PlayState* play) {
    s32 pad;
    Vec3f sp40;
    Vec3f sp34;
    f32 temp_f0;
    s32 temp_v0;

    if (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        temp_v0 = (s32)(this->dyna.actor.scale.y * 130.0f) - 3;
        if (temp_v0 > 0) {
            this->unk_2AC += temp_v0;
        }

        if (this->unk_2AC >= 10) {
            this->unk_2AC = 0;
            sp34.x = (Rand_ZeroOne() * 600.0f) - 300.0f;
            sp34.y = 600.0f;
            sp34.z = (Rand_ZeroOne() * 600.0f) - 300.0f;

            temp_f0 = sqrtf(this->dyna.actor.scale.y + 0.01f);
            sp40.x = sp34.x * 0.006935f * temp_f0;
            sp40.y = 2.0f;
            sp40.z = sp34.z * 0.006935f * temp_f0;

            sp34.x = (this->dyna.actor.scale.x * sp34.x) + this->dyna.actor.world.pos.x;
            sp34.y = (this->dyna.actor.scale.y * sp34.y) + this->dyna.actor.world.pos.y;
            sp34.z = (this->dyna.actor.scale.z * sp34.z) + this->dyna.actor.world.pos.z;

            if ((this->unk_244 - 3.0f) < sp34.y) {
                EffectSsIceSmoke_Spawn(play, &sp34, &sp40, &gZeroVec3f, (s32)(this->dyna.actor.scale.y * 1300.0f) + 60);
            }
        }
    }
}
