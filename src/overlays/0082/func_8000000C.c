// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_boom.h"

void ref_func_808A24DC(EnBoom* this, PlayState* play) {
    WaterBox* waterBox;
    f32 sp50 = this->actor.world.pos.y;
    u16 sp4E = this->actor.bgCheckFlags & BGCHECKFLAG_WATER;

    if (BgCheck_GetWaterSurfaceNoBgIdAlt(play, &play->colCtx, this->actor.world.pos.x, this->actor.world.pos.z, &sp50,
                                         &waterBox) &&
        (this->actor.world.pos.y < sp50)) {
        Vec3f sp40;

        this->actor.bgCheckFlags |= BGCHECKFLAG_WATER;
        sp40.x = this->actor.world.pos.x;
        sp40.y = this->actor.world.pos.y - 20.0f;
        sp40.z = this->actor.world.pos.z;
        EffectSsBubble_Spawn(play, &sp40, 20.0f, 10.0f, 20.0f, 0.13f);
    } else {
        this->actor.bgCheckFlags &= ~BGCHECKFLAG_WATER;
    }

    if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER_TOUCH) &&
        ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER) != sp4E)) {
        Vec3f sp34;

        Math_Vec3f_Diff(&this->actor.world.pos, &this->actor.prevPos, &sp34);
        if (sp34.y != 0.0f) {
            f32 temp_fv0 = sqrtf(SQ(sp34.x) + SQ(sp34.z));

            if (temp_fv0 != 0.0f) {
                temp_fv0 = (((sp50 - this->actor.prevPos.y) / sp34.y) * temp_fv0) / temp_fv0;
            }

            sp34.x = this->actor.prevPos.x + (sp34.x * temp_fv0);
            sp34.y = sp50;
            sp34.z = this->actor.prevPos.z + (sp34.z * temp_fv0);
            EffectSsGSplash_Spawn(play, &sp34, NULL, NULL, 0, 300);
        }

        Actor_PlaySfx(&this->actor, NA_SE_EV_DIVE_INTO_WATER_L);

        EffectSsGRipple_Spawn(play, &sp34, 100, 500, 0);
        EffectSsGRipple_Spawn(play, &sp34, 100, 500, 4);
        EffectSsGRipple_Spawn(play, &sp34, 100, 500, 8);
    }

    this->actor.bgCheckFlags |= BGCHECKFLAG_WATER_TOUCH;
}
