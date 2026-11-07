// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_switch.h"

void ref_func_80B16400(BgHakuginSwitch* this, PlayState* play) {
    if (Math_StepToF(&this->dyna.actor.world.pos.y,
                     (this->dyna.actor.home.pos.y + 2.0f) - (1800.0f * this->dyna.actor.scale.y), 10.0f)) {
        if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
            Rumble_Request(this->dyna.actor.xyzDistToPlayerSq, 120, 20, 10);
        }
        ref_func_80B16494(this, play);
    }
}
