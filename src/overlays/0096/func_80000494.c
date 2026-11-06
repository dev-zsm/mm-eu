// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B8924(DoorWarp1* this, PlayState* play) {
    this->unk_1C4 = 0;
    this->unk_1C6 = -140;
    this->unk_1C8 = -80;
    this->unk_1BC = 1.0f;
    this->unk_1B0 = 0.0f;
    this->unk_1B4 = 0.0f;
    this->unk_1B8 = 0.0f;
    this->unk_1A4 = 0.3f;
    this->unk_1A8 = 0.3f;
    this->unk_1AC = 0.0f;
    this->dyna.actor.shape.yOffset = 1.0f;
    this->unk_1D0 = 0;
    ref_D_808BC000 = 100;
    Lights_PointNoGlowSetInfo(&this->unk_1E0, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                              this->dyna.actor.world.pos.z, 200, 255, 255, 255);
    Lights_PointNoGlowSetInfo(&this->unk_1F4, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                              this->dyna.actor.world.pos.z, 200, 255, 255, 255);
    DoorWarp1_SetupAction(this, ref_func_808B96B0);
}
