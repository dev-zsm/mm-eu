// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kzsaku.h"

void ObjKzsaku_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjKzsaku* this = (ObjKzsaku*)thisx;
    CollisionHeader* col = NULL;

    Actor_SetScale(&this->dyna.actor, 1.0f);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    CollisionHeader_GetVirtual(&gUnderwaterGrateCol, &col);

    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, thisx, col);

    this->switchFlag = KZSAKU_GET_SWITCH_FLAG(thisx);
    this->raisedAmount = 0.0f;

    if (Flags_GetSwitch(play, this->switchFlag)) {
        ref_func_80C08C84(this);
    } else {
        ObjKzsaku_SetupIdle(this);
    }
}
