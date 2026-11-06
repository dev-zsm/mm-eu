// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_last_bwall.h"

void BgLastBwall_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgLastBwall* this = (BgLastBwall*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, ref_D_80C18AC8);
    this->type = BGLASTBWALL_GET_TYPE(&this->dyna.actor);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, ref_D_80C18A48[this->type].colHeader);
    Collider_InitTris(play, &this->colliderTris);
    if (Flags_GetSwitch(play, BGLASTBWALL_GET_SWITCH_FLAG(&this->dyna.actor))) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if (!Collider_SetTris(play, &this->colliderTris, &this->dyna.actor, &sTrisInit, this->colliderTrisElement)) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    BgLastBwall_InitCollider(&sTrisInit, &this->dyna.actor.world.pos, &this->dyna.actor.shape.rot, &this->colliderTris,
                             ref_D_80C18AC0[this->type]);
    SubS_FillCutscenesList(&this->dyna.actor, this->csIdList, ARRAY_COUNT(this->csIdList));
    ref_func_80C187E4(this);
}
