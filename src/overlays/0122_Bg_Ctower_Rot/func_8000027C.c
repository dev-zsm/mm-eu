// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ctower_rot.h"

void BgCtowerRot_DoorClose(BgCtowerRot* this, PlayState* play) {
    if (!Math_SmoothStepToF(&this->timer, 0.0f, 0.1f, 15.0f, 0.1f)) {
        if (this->dyna.actor.params == BGCTOWERROT_STONE_DOOR_MAIN) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_STONEDOOR_STOP);
            CutsceneManager_Stop(this->dyna.actor.csId);
        }
        this->actionFunc = BgCtowerRot_DoorDoNothing;
    } else if (this->dyna.actor.params == BGCTOWERROT_STONE_DOOR_MAIN) {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_STONE_STATUE_OPEN - SFX_FLAG);
    }
    this->dyna.actor.world.pos.x =
        this->dyna.actor.home.pos.x + (Math_SinS(this->dyna.actor.world.rot.y) * this->timer);
    this->dyna.actor.world.pos.z =
        this->dyna.actor.home.pos.z + (Math_CosS(this->dyna.actor.world.rot.y) * this->timer);
}
