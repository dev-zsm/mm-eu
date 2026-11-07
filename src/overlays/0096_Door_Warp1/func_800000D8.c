// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B8568(DoorWarp1* this, PlayState* play) {
    s32 pad[2];

    Lights_PointNoGlowSetInfo(&this->unk_1E0, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                              this->dyna.actor.world.pos.z, 0, 0, 0, 0);
    this->unk_1DC = LightContext_InsertLight(play, &play->lightCtx, &this->unk_1E0);
    Lights_PointNoGlowSetInfo(&this->unk_1F4, this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y,
                              this->dyna.actor.world.pos.z, 0, 0, 0, 0);
    this->unk_1F0 = LightContext_InsertLight(play, &play->lightCtx, &this->unk_1F4);
}
