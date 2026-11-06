// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_slime.h"

void EnSlime_SetupDamaged(EnSlime* this, PlayState* play, s32 arg2) {
    s32 i;
    Vec3f effectVelocity;
    Vec3f effectPos;
    f32 ySin;
    f32 yCos;

    this->collider.base.acFlags &= ~AC_ON;
    if (this->actor.velocity.y > 0.0f) {
        this->actor.velocity.y = 0.0f;
    }
    Actor_SetColorFilter(&this->actor, COLORFILTER_COLORFLAG_RED, 255, COLORFILTER_BUFFLAG_XLU, 20);
    this->timer = 20;
    this->actor.speed = 10.0f;
    if (arg2 == true) {
        
        ref_func_800BE504(&this->actor, &this->collider);
    }

    this->eyeTexIndex = EN_SLIME_EYETEX_OPEN;
    Actor_SetScale(&this->actor, 0.01f);
    this->wobbleRot.x = Rand_ZeroOne() * (M_PIf * 2);
    this->wobbleRot.z = Rand_ZeroOne() * (M_PIf * 2);
    ySin = Math_SinS(this->actor.world.rot.y) * 10.0f;
    yCos = Math_CosS(this->actor.world.rot.y) * 10.0f;
    effectPos.x = this->actor.world.pos.x + ySin;
    effectPos.y = this->actor.world.pos.y + 20.0f;
    effectPos.z = this->actor.world.pos.z + yCos;
    EffectSsGSplash_Spawn(play, &effectPos, NULL, NULL, 1, 550);

    for (i = 0; i < 10; i++) {
        effectPos.x = Rand_CenteredFloat(40.0f) + this->actor.world.pos.x + ySin;
        effectPos.y = Rand_CenteredFloat(10.0f) + this->actor.world.pos.y + 40.0f;
        effectPos.z = Rand_CenteredFloat(40.0f) + this->actor.world.pos.z + yCos;

        effectVelocity.x = ((Rand_ZeroOne() * 3.5f) + 1.0f) * -Math_SinS(this->actor.world.rot.y);
        effectVelocity.z = ((Rand_ZeroOne() * 3.5f) + 1.0f) * -Math_CosS(this->actor.world.rot.y);

        effectVelocity.y = (Rand_ZeroOne() * 6.0f) + 2.0f;
        EffectSsDtBubble_SpawnCustomColor(play, &effectPos, &effectVelocity, &sBubbleAccel, &sBubblePrimColor,
                                          &sBubbleEnvColor, Rand_S16Offset(40, 20), 20, 0);
    }

    if (this->actor.colChkInfo.health == 0) {
        Actor_PlaySfx(&this->actor, NA_SE_EN_SLIME_DEAD);
    } else {
        Actor_PlaySfx(&this->actor, NA_SE_EN_SLIME_DAMAGE);
    }
    this->actionFunc = EnSlime_Damaged;
}
