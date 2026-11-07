// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void BgSpdweb_Init(Actor* thisx, PlayState* play) {
    BgSpdweb* this = (BgSpdweb*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->unk_161 = 0;
    this->switchFlag = BGSPDWEB_GET_SWITCH_FLAG(&this->dyna.actor);
    thisx->params &= 0xFF;
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);

    if (this->dyna.actor.params == BGSPDWEB_FF_0) {
        Collider_InitAndSetTris(play, &this->collider, &this->dyna.actor, &sTrisInit1, this->colliderElements);
        ref_func_809CE068(this);
        DynaPolyActor_LoadMesh(play, &this->dyna, &object_spdweb_Colheader_002678);
        this->unk_2F8 = play->colCtx.dyna.bgActors[this->dyna.bgId].colHeader->vtxList;
        this->unk_164 = 0.0f;
        this->actionFunc = ref_func_809CE4C8;
    } else {
        Collider_InitAndSetTris(play, &this->collider, &this->dyna.actor, &sTrisInit2, this->colliderElements);
        ref_func_809CE068(this);
        DynaPolyActor_LoadMesh(play, &this->dyna, &object_spdweb_Colheader_0011C0);
        this->actionFunc = ref_func_809CEBC0;
        Actor_SetFocus(&this->dyna.actor, 30.0f);
    }

    this->unk_162 = 0;

    if (Flags_GetSwitch(play, this->switchFlag)) {
        Actor_Kill(&this->dyna.actor);
    }
}
