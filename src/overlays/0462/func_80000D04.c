// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B16494(BgHakuginSwitch* this, PlayState* play) {
    this->unk_1C0 = 0;
    this->dyna.actor.world.pos.y = (this->dyna.actor.home.pos.y - (1800.0f * this->dyna.actor.scale.y)) + 2.0f;
    if ((BGHAKUGINSWITCH_GET_7(&this->dyna.actor) == BGHAKUGINSWITCH_GET_7_1) &&
        (this->dyna.actor.category != ACTORCAT_PROP)) {
        Actor_ChangeCategory(play, &play->actorCtx, &this->dyna.actor, ACTORCAT_PROP);
    }
    this->actionFunc = ref_func_80B16520;
}
