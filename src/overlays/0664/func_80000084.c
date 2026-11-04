// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ending.h"

void ObjEnding_Draw(Actor* thisx, PlayState* play) {
    ObjEnding* this = (ObjEnding*)thisx;
    Gfx* dl1;
    Gfx* dl2;

    if (this->animMat != NULL) {
        AnimatedMat_Draw(play, this->animMat);
    }
    dl1 = this->modelInfo->dLists[0];
    if (dl1 != NULL) {
        Gfx_DrawDListOpa(play, dl1);
    }
    dl2 = this->modelInfo->dLists[1];
    if (dl2 != NULL) {
        Gfx_DrawDListXlu(play, dl2);
    }
}
