// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void BgHakuginPost_Init(Actor* thisx, PlayState* play) {
    static s32 ref_D_80A9D8FC = 1;
    BgHakuginPost* this = (BgHakuginPost*)thisx;

    if (ref_D_80A9D8FC != 0) {
        ref_D_80A9D8FC = 0;
        ref_func_80A9ACD0(&ref_D_80A9E028);
        ref_func_80A9ACF0();
    }

    if (BGHAKUGINPOST_GET_7(&this->dyna.actor) == 7) {
        Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
        this->dyna.actor.world.rot.x = 0;
        this->dyna.actor.world.rot.z = 0;
        this->dyna.actor.shape.rot.x = 0;
        this->dyna.actor.shape.rot.z = 0;
        DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
        DynaPolyActor_LoadMesh(play, &this->dyna, &object_hakugin_obj_Colheader_00D3B0);
        ref_func_80A9B3BC(this, play);
        ref_func_80A9CA94(this);
    } else {
        ref_func_80A9AFB4(this, play, &ref_D_80A9E028);
        Actor_Kill(&this->dyna.actor);
    }
}
