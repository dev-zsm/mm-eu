// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lift.h"

void ref_func_8093DA48(ObjLift* this, PlayState* play) {
    s32 pad;
    s32 bgId;
    Vec3f pos;

    Actor_MoveWithGravity(&this->dyna.actor);
    Math_Vec3f_Copy(&pos, &this->dyna.actor.prevPos);
    pos.y += yOffsets[OBJLIFT_GET_1(&this->dyna.actor)];
    this->dyna.actor.floorHeight =
        BgCheck_EntityRaycastFloor5(&play->colCtx, &this->dyna.actor.floorPoly, &bgId, &this->dyna.actor, &pos);
    if ((yOffsets[OBJLIFT_GET_1(&this->dyna.actor)] - 0.001f) <=
        (this->dyna.actor.floorHeight - this->dyna.actor.world.pos.y)) {
        ref_func_8093D3C0(this, play);
        SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 20, NA_SE_EV_BOX_BREAK);
        if (this->unk_178 > 0) {
            ref_func_8093DB70(this);
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        } else {
            Flags_SetSwitch(play, OBJLIFT_GET_SWITCH_FLAG(&this->dyna.actor));
            Actor_Kill(&this->dyna.actor);
        }
    }
}
