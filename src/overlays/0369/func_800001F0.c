// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_purify.h"

void ref_func_80A84EC0(ObjPurify* this, PlayState* play) {
    s32 pad;
    s32 sp28;
    s32 index;

    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        sp28 = OBJPURIFY_GET_UNK_FLAG(&this->dyna.actor);
        index = OBJPURIFY_GET_INFO_INDEX(&this->dyna.actor);
        this->dyna.actor.objectSlot = this->objectSlot;
        Actor_SetObjectDependency(play, &this->dyna.actor);
        if (sp28 == 1) {
            DynaPolyActor_LoadMesh(play, &this->dyna, sObjPurifyInfo[index].colHeader);
            ref_func_80A84FA0(this);
        } else if (ObjPurify_IsPurified(this)) {
            ref_func_80A8515C(this);
        } else {
            ref_func_80A84FEC(this);
        }
    }
}
