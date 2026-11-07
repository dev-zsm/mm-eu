// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

void BgHakuginBombwall_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgHakuginBombwall* this = (BgHakuginBombwall*)thisx;
    BgHakuginBombwallStruct* ptr = &ref_D_80ABCFC0[BGHAKUGIN_BOMBWALL_100(&this->dyna.actor)];

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, 0);
    Collider_InitCylinder(play, &this->collider);

    if (Flags_GetSwitch(play, BGHAKUGIN_BOMBWALL_SWITCH_FLAG(&this->dyna.actor))) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    DynaPolyActor_LoadMesh(play, &this->dyna, ptr->unk_00);

    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    this->collider.dim.radius = ptr->unk_14;
    this->collider.dim.height = ptr->unk_16;
    this->collider.elem.acDmgInfo.dmgFlags = ptr->unk_18;
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);

    Actor_SetFocus(&this->dyna.actor, ptr->unk_08);
    this->dyna.actor.cullingVolumeScale = ptr->unk_0C;
    this->dyna.actor.cullingVolumeDownward = ptr->unk_10;
    this->actionFunc = ref_func_80ABCCE4;
}
