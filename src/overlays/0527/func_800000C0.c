// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_inibs_movebg.h"

void BgInibsMovebg_Draw(Actor* thisx, PlayState* play) {
    BgInibsMovebg* this = (BgInibsMovebg*)thisx;
    AnimatedMaterial* sandTexAnim;
    Gfx* opaDList;
    Gfx* xluDList;

    sandTexAnim = this->sandTexAnim;
    if (sandTexAnim != NULL) {
        AnimatedMat_Draw(play, Lib_SegmentedToVirtual(this->sandTexAnim));
    }

    opaDList = this->opaDList;
    if (opaDList != NULL) {
        Gfx_DrawDListOpa(play, this->opaDList);
    }

    xluDList = this->xluDList;
    if (xluDList != NULL) {
        Gfx_DrawDListXlu(play, this->xluDList);
    }
}
