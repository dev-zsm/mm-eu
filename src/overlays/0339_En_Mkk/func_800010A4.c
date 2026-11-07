// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4EF74(EnMkk* this, PlayState* play) {
    s32 newAlpha = this->alpha - 20;

    if (newAlpha <= 0) {
        if (this->unk_14B & 8) {
            Actor_SetScale(&this->actor, 0.01f);
            this->primColorSelect = 0;
            this->unk_149 = 0;
            Math_Vec3f_Copy(&this->actor.world.pos, &this->actor.home.pos);
            Math_Vec3f_Copy(&this->unk_154, &this->actor.world.pos);
            Math_Vec3f_Copy(&this->unk_160, &this->actor.world.pos);
            this->actor.speed = 0.0f;
            this->actor.velocity.y = 0.0f;
            ref_func_80A4EDF0(this);
        } else {
            Actor_Kill(&this->actor);
        }
    } else {
        this->alpha = newAlpha;
        this->actor.world.pos.x += 0.3f + (3.0f * Rand_ZeroOne());
        this->actor.world.pos.y += 0.5f + (3.5f * Rand_ZeroOne());
        this->unk_16C.x -= 0.3f + (3.0f * Rand_ZeroOne());
        this->unk_16C.y += 0.5f + (3.5f * Rand_ZeroOne());
        this->unk_154.z += 0.3f + (3.0f * Rand_ZeroOne());
        this->unk_154.y += 0.5f + (3.5f * Rand_ZeroOne());
        this->unk_160.z -= 0.3f + (3.0f * Rand_ZeroOne());
        this->unk_160.y += 0.5f + (3.5f * Rand_ZeroOne());
    }
}
