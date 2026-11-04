// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_inibs_movebg.h"

void BgInibsMovebg_Init(Actor* thisx, PlayState* play) {
    BgInibsMovebg* this = (BgInibsMovebg*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);

    this->opaDList = sOpaDLists[BG_INIBS_MOVEBG_GET_MODE(thisx)];
    this->xluDList = sXluDLists[BG_INIBS_MOVEBG_GET_MODE(thisx)];
    this->sandTexAnim = sSandTexAnims[BG_INIBS_MOVEBG_GET_MODE(thisx)];
}
