// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ghaka.h"

void ObjGhaka_Init(Actor* thisx, PlayState* play) {
    ObjGhaka* this = (ObjGhaka*)thisx;
    s32 pad;
    CollisionHeader* colHeader = NULL;

    Actor_ProcessInitChain(&this->dyna.actor, ref_D_80B3C96C);
    Actor_SetScale(&this->dyna.actor, 0.1f);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    CollisionHeader_GetVirtual(&object_ghaka_Colheader_003CD0, &colHeader);
    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    Actor_UpdateBgCheckInfo(play, &this->dyna.actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);
    if (this->dyna.actor.floorPoly == NULL) {
        Actor_Kill(&this->dyna.actor);
    }
    if (CHECK_WEEKEVENTREG(WEEKEVENTREG_20_20)) {
        ref_func_80B3C2C4(this, play);
    }
    ref_func_80B3C260(this);
}
