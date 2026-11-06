// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

s32 ref_func_80B7EDC4(BgIkanaBlock* this, PlayState* play) {
    s32 pad;
    Vec3f sp30;
    s32 bgId;

    sp30.x = this->dyna.actor.world.pos.x;
    sp30.y = this->dyna.actor.world.pos.y + this->unk_170 + 40.0f;
    sp30.z = this->dyna.actor.world.pos.z;

    this->dyna.actor.floorHeight = BgCheck_EntityRaycastFloor5_2(play, &play->colCtx, &this->dyna.actor.floorPoly,
                                                                 &bgId, &this->dyna.actor, &sp30);
    this->dyna.actor.floorBgId = bgId;

    return ((this->dyna.actor.world.pos.y + this->unk_170) - this->dyna.actor.floorHeight) < 2.0f;
}
