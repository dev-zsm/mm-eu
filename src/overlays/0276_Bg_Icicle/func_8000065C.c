// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icicle.h"

void BgIcicle_UpdateAttacked(BgIcicle* this, PlayState* play) {
    s32 dropItem00Id;

    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;

        if (this->dyna.actor.params == ICICLE_STALAGMITE_RANDOM_DROP) {
            BgIcicle_Break(this, play, 50.0f);

            if (this->unk_160 != 0xFF) {
                Item_DropCollectibleRandom(play, NULL, &this->dyna.actor.world.pos, this->unk_160 << 4);
            }
        } else if (this->dyna.actor.params == ICICLE_STALAGMITE_FIXED_DROP) {
            dropItem00Id = ref_func_800A8150(this->unk_160);
            BgIcicle_Break(this, play, 50.0f);
            Item_DropCollectible(play, &this->dyna.actor.world.pos, (this->unk_161 << 8) | dropItem00Id);
        } else {
            if (this->dyna.actor.params == ICICLE_STALACTITE_REGROW) {
                BgIcicle_Break(this, play, 40.0f);
                this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + 120.0f;
                DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
                this->actionFunc = BgIcicle_Regrow;
                return;
            }

            BgIcicle_Break(this, play, 40.0f);
        }

        Actor_Kill(&this->dyna.actor);
    }
}
