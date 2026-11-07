// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ending.h"

void ObjEnding_Init(Actor* thisx, PlayState* play) {
    ObjEnding* this = (ObjEnding*)thisx;
    AnimatedMaterial* animMat;

    Actor_ProcessInitChain(thisx, sInitChain);
    this->modelInfo = &sModelInfo[thisx->params];
    animMat = this->modelInfo->animMat;
    if (animMat != NULL) {
        this->animMat = Lib_SegmentedToVirtual(animMat);
    }
}
