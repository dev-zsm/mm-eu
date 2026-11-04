// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

void ObjPzlblock_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjPzlblock* this = (ObjPzlblock*)thisx;
    s32 sp2C = OBJPZLBLOCK_GET_ROTZ(&this->dyna.actor);
    s32 sp28 = this->dyna.actor.home.rot.x & 0xF;
    ObjPzlblockStruct* sp24 = &ref_D_809A4060[OBJPZLBLOCK_GET_1000(&this->dyna.actor)];

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    Actor_SetScale(&this->dyna.actor, 0.1f);

    this->dyna.actor.home.rot.y = 0;
    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;

    DynaPolyActor_Init(&this->dyna, 0);

    this->objectSlot = Object_GetSlot(&play->objectCtx, sp24->objectId);

    if (sp28 == 0) {
        ref_func_809A3D1C(this);
    } else if (Flags_GetSwitch(play, OBJPZLBLOCK_GET_SWITCH_FLAG(&this->dyna.actor))) {
        if (sp2C == 0) {
            this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + (sp28 * 60);
            ref_func_809A3D1C(this);
        } else if (sp2C == 1) {
            this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x - (sp28 * 60);
            ref_func_809A3D1C(this);
        } else if (sp2C == 2) {
            this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + (sp28 * 60);
            ref_func_809A3D1C(this);
        } else if (sp2C == 3) {
            this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z - (sp28 * 60);
            ref_func_809A3D1C(this);
        } else {
            ref_func_809A3A48(this);
        }
    } else {
        ref_func_809A3A48(this);
    }
}
