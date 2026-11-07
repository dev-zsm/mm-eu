// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_uzu.h"

void EnWarpUzu_Init(Actor* thisx, PlayState* play) {
    EnWarpUzu* this = (EnWarpUzu*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitAndSetCylinder(play, &this->collider, thisx, &sCylinderInit);
    thisx->attentionRangeType = ATTENTION_RANGE_0;
    ref_func_80A66208(this, play);
}
