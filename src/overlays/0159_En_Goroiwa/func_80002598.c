// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

void ref_func_80940E38(EnGoroiwa* this, PlayState* play) {
    f32 sp5C;
    s32 pad;
    f32 sp54;
    Vec3f sp48;
    s16 sp46;
    s16 temp_a0;

    if (this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) {
        if (this->actor.xzDistToPlayer < 1000.0f) {
            sp5C = (1000.0f - this->actor.xzDistToPlayer) * 0.0012f * (this->actor.speed * 0.1f);
            if (Rand_ZeroOne() < sp5C) {
                this->unk_1CE += 20000;
                sp46 = (s32)Rand_ZeroFloat(20000.0f) + this->unk_1CE;
                temp_a0 = sp46 - this->actor.world.rot.y;
                if (ABS(temp_a0) < 0x4000) {
                    sp54 = Math_CosS(temp_a0) * 1.6f * this->unk_1DC;
                } else {
                    sp54 = this->unk_1DC;
                }

                sp48.x = (Math_SinS(sp46) * sp54) + this->actor.world.pos.x;
                sp48.y = this->actor.world.pos.y + 20.0f;
                sp48.z = (Math_CosS(sp46) * sp54) + this->actor.world.pos.z;

                ref_func_800B0E48(play, &sp48, &ref_D_80942E48, &ref_D_80942E54, &ref_D_80942E38, &ref_D_80942E44,
                              (Rand_ZeroOne() * 600.0f) + (600.0f * (this->actor.scale.x + 0.1f) * 0.5f),
                              (s32)(Rand_ZeroOne() * 50.0f) + 30);
            }
        }
    }
}
