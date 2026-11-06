// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_purify.h"

void ObjPurify_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjPurify* this = (ObjPurify*)thisx;
    ObjPurifyInfo* info = &sObjPurifyInfo[OBJPURIFY_GET_INFO_INDEX(&this->dyna.actor)];
    s32 sp20 = OBJPURIFY_GET_UNK_FLAG(thisx);

    Actor_SetScale(&this->dyna.actor, info->scale);
    if (sp20 == 1) {
        DynaPolyActor_Init(&this->dyna, 0);
    }
    this->objectSlot = Object_GetSlot(&play->objectCtx, info->objectId);
    if (this->objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->dyna.actor);
    } else if (sp20 == 0) {
        ref_func_80A84EAC(this);
    } else if (ObjPurify_IsPurified(this)) {
        Actor_Kill(&this->dyna.actor);
    } else {
        ref_func_80A84EAC(this);
    }
}
