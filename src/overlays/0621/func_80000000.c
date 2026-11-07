// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikninside.h"

void BgIkninside_Init(Actor* thisx, PlayState* play) {
    BgIkninside* this = (BgIkninside*)thisx;
    CollisionHeader* colHeader = NULL;
    s32 pad;

    Actor_SetScale(&this->dyna.actor, 0.1f);
    this->actionFunc = ref_func_80C072D0;
    DynaPolyActor_Init(&this->dyna, 0);
    CollisionHeader_GetVirtual(&object_ikninside_obj_Colheader_00DE48, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    Collider_InitAndSetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
    if (Flags_GetSwitch(play, DMIKNINSIDE_GET_SWITCH_FLAG(thisx))) {
        Actor_Kill(&this->dyna.actor);
    }
}
