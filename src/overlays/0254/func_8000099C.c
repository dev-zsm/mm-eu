// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

void ObjPzlblock_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjPzlblock* this = (ObjPzlblock*)thisx;

    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y;
    Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 15.0f, 30.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);

    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        ObjPzlblockStruct* sp2C = &ref_D_809A4060[OBJPZLBLOCK_GET_1000(&this->dyna.actor)];

        this->dyna.actor.objectSlot = this->objectSlot;
        Actor_SetObjectDependency(play, &this->dyna.actor);
        DynaPolyActor_LoadMesh(play, &this->dyna, sp2C->unk_04);
        this->dyna.actor.update = ref_func_809A3E58;
        this->dyna.actor.draw = ref_func_809A3F0C;
    }
}
