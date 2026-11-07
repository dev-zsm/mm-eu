// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5E4BC(EnKusa2* this, PlayState* play) {
    Math_StepToF(&this->actor.scale.y, 0.4f, 0.032f);
    Math_StepToF(&this->actor.scale.x, 0.4f, 0.032f);
    this->actor.scale.z = this->actor.scale.x;
    Actor_MoveWithGravity(&this->actor);
    ref_func_80A5BAFC(this, play);
    ref_func_80A5BF60(this, 6);
    this->actor.shape.rot.x -= 0x5DC;
    this->actor.shape.rot.y += this->unk_1CC;

    if ((this->actor.bgCheckFlags & BGCHECKFLAG_WATER) && (this->actor.depthInWater > 5.0f) &&
        (Rand_ZeroOne() < 0.8f)) {
        EffectSsBubble_Spawn(play, &this->actor.world.pos, 20.0f, 10.0f, 20.0f, (Rand_ZeroOne() * 0.08f) + 0.04f);
    }

    this->unk_1CF -= 15;
    if (this->unk_1CF <= 15) {
        Actor_Kill(&this->actor);
    }
}
