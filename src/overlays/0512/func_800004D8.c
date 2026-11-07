// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void BgIkanaBlock_Init(Actor* thisx, PlayState* play) {
    BgIkanaBlock* this = (BgIkanaBlock*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gameplay_dangeon_keep_Colheader_007498);
    DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    this->unk_15C = Lib_SegmentedToVirtual(gameplay_dangeon_keep_Matanimheader_01B370);
    this->unk_174 = this->dyna.actor.shape.rot;
    ref_func_80B7ED54(this);
    ref_func_80B7F00C(this);
}
