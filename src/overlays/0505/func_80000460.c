// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

void BgKin2Shelf_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgKin2Shelf* this = (BgKin2Shelf*)thisx;
    s32 sp24 = BGKIN2SHELF_GET_1(&this->dyna.actor);

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);

    if (sp24 == 0) {
        this->dyna.actor.cullingVolumeScale = 150.0f;
        this->dyna.actor.cullingVolumeDownward = 140.0f;
        Actor_SetScale(&this->dyna.actor, 0.1f);
    } else {
        this->dyna.actor.cullingVolumeScale = 250.0f;
        this->dyna.actor.cullingVolumeDownward = 300.0f;
        Actor_SetScale(&this->dyna.actor, 1.0f);
        this->dyna.actor.flags |= ACTOR_FLAG_UCODE_POINT_LIGHT_ENABLED;
    }

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, ref_D_80B70780[sp24]);
    ref_func_80B700A8(this);
}
