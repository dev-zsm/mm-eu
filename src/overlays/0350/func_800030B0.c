// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5E210(EnKusa2* this, PlayState* play) {
    Math_StepToF(&this->actor.gravity, -4.0f, 0.5f);

    if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
        this->actor.speed *= 0.4f;
        if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND_TOUCH) {
            ref_func_80A5D178(this);
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EN_KUSAMUSHI_HIDE);
        }
    }

    Actor_MoveWithGravity(&this->actor);
    ref_func_80A5BAFC(this, play);

    if (this->actor.velocity.y > 0.01f) {
        ref_func_80A5BF38(this, 4);
        this->unk_1CC += 1000;
    } else {
        ref_func_80A5BF60(this, 10);
        this->unk_1CF -= 20;
        this->unk_1CC += 5000;
    }

    if (this->unk_1CC > 20000) {
        this->unk_1CC = 20000;
    }

    this->actor.shape.rot.y += this->unk_1CC;

    if (this->actor.velocity.y > 1.0f) {
        Math_StepToF(&this->actor.scale.y, 0.24000001f, 0.080000006f);
        Math_StepToF(&this->actor.scale.x, 0.32000002f, 0.040000003f);
    } else if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
        Math_StepToF(&this->actor.scale.y, 0.0f, 0.120000005f);
        Math_StepToF(&this->actor.scale.x, 0.48000002f, 0.120000005f);
    } else {
        Math_StepToF(&this->actor.scale.y, 0.56f, 0.1f);
        Math_StepToF(&this->actor.scale.x, 0.24000001f, 0.1f);
    }

    this->actor.scale.z = this->actor.scale.x;

    if (this->unk_1CF <= 20) {
        if (this->unk_1B8 != NULL) {
            this->unk_1B8->unk_28 = ref_func_80A5C718;
        }
        Actor_Kill(&this->actor);
    }
}
