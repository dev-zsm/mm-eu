// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B236C8(EnHanabi* this, PlayState* play) {
    Vec3f sp34;
    f32 sp30;
    s32 pad;
    s32 sp28;

    this->actor.draw = EnHanabi_Draw;
    ref_func_80B234C8(this);
    if (this->actor.home.rot.x != 0) {
        if (this->unk_144 > 0) {
            this->unk_144--;
            return;
        }

        Math_Vec3f_Copy(&sp34, &this->actor.world.pos);

        if (this->actor.home.rot.x != 0) {
            sp30 = Rand_ZeroFloat(200.0f) + this->actor.home.rot.x;
        } else {
            sp30 = Rand_ZeroFloat(200.0f) + 300.0f;
        }

        sp34.x += sp30 * Math_SinS(this->actor.home.rot.y);
        sp34.y += Rand_CenteredFloat(300.0f);
        sp34.z += sp30 * Math_CosS(this->actor.home.rot.y);

        if (this->actor.home.rot.x > 0x258) {
            sp28 = ref_func_80B22C80(&sp34, this->unk_148, 2.0f);
        } else {
            sp28 = ref_func_80B22C80(&sp34, this->unk_148, 1.0f);
        }

        this->actor.home.rot.y += TRUNCF_BINANG((Rand_ZeroFloat(40.0f) + 80.0f) * 256.0f);
        this->unk_144 = (s32)Rand_ZeroFloat(5.0f) + 20;
        Actor_PlaySfx(&this->actor, NA_SE_OC_FIREWORKS);
        ref_func_80B235CC(this, &sp34, sp28);
    }
}
