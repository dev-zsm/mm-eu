// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_lotus.h"

void ref_func_80AD6A88(BgLotus* this, PlayState* play) {
    if (this->dyna.actor.world.pos.y > this->unk160) {
        this->dyna.actor.world.pos.y = this->unk160;
    }
    this->dyna.actor.world.pos.y -= 1.0f;
    if (this->dyna.actor.world.pos.y <= this->dyna.actor.floorHeight) {
        this->dyna.actor.world.pos.y = this->dyna.actor.floorHeight;
        this->unk166 = 0;
    }
    if (this->unk166 > 0) {
        this->unk166--;
        ref_func_80AD6830(this);
    } else {
        if (Math_StepToF(&this->dyna.actor.scale.x, 0.0f, 5.0f * 0.001f)) {
            this->dyna.actor.draw = NULL;
            this->unk166 = 100;
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            this->actionFunc = ref_func_80AD6B68;
        }
        this->dyna.actor.scale.z = this->dyna.actor.scale.x;
    }
}
