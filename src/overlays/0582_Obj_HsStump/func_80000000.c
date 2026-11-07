// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hsstump.h"

void ObjHsStump_Init(Actor* thisx, PlayState* play) {
    ObjHsStump* this = (ObjHsStump*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->isHidden = OBJHSSTUMP_GET_ISHIDDEN(thisx);
    this->switchFlag = OBJHSSTUMP_GET_SWITCH_FLAG(thisx);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_hsstump_Colheader_0011B0);
    switch (this->isHidden) {
        case true:
            if (Flags_GetSwitch(play, this->switchFlag)) {
                this->isHidden = false;
            } else {
                this->dyna.actor.draw = NULL;
                Actor_SetScale(&this->dyna.actor, 0.0f);
                DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            }
            FALLTHROUGH;
        case false:
            ObjHsStump_SetupIdle(this, play);
            break;

        default:
            break;
    }
}
