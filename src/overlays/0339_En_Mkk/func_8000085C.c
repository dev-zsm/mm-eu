// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4E72C(EnMkk* this, PlayState* play) {
    Vec3f temp;

    if (this->actor.bgCheckFlags & BGCHECKFLAG_GROUND) {
        if (this->actor.velocity.y > -1.0f) {
            temp.x = this->actor.world.pos.x;
            temp.y = this->actor.world.pos.y + 15.0f;
            temp.z = this->actor.world.pos.z;
            EffectSsDeadDb_Spawn(play, &temp, &gZeroVec3f, &gZeroVec3f, &sEffPrimColors[this->actor.params],
                                 &sEffEnvColors[this->actor.params], 0x46, 4, 0xC);
            Actor_PlaySfx(&this->actor, NA_SE_EN_EXTINCT);
            if (this->unk_14C != 0) {
                Item_DropCollectibleRandom(play, &this->actor, &this->actor.world.pos, this->unk_14C * 0x10);
            }
            ref_func_80A4EEF4(this);
        } else {
            this->actor.velocity.y *= -0.8f;
            this->actor.bgCheckFlags &= ~BGCHECKFLAG_GROUND;
        }
    }
}
