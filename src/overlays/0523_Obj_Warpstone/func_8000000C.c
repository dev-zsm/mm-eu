// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_warpstone.h"

void ObjWarpstone_Init(Actor* thisx, PlayState* play) {
    ObjWarpstone* this = (ObjWarpstone*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    Collider_InitAndSetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    Actor_SetFocus(&this->dyna.actor, 40.0f);

    if (!GET_OWL_STATUE_ACTIVATED(OBJ_WARPSTONE_GET_OWL_WARP_ID(&this->dyna.actor))) {
        ObjWarpstone_SetupAction(this, ObjWarpstone_ClosedIdle);
    } else {
        ObjWarpstone_SetupAction(this, ObjWarpstone_OpenedIdle);
        this->modelIndex = SEK_MODEL_OPENED;
    }
}
