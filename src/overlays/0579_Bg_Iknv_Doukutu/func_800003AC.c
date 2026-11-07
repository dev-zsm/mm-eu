// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_doukutu.h"

void BgIknvDoukutu_FadeInWater(BgIknvDoukutu* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, this->cueType) &&
        (play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id == 3)) {
        this->actionFunc = BgIknvDoukutu_FillSpring;
    }

    if (this->opacity < 0.95f) {
        this->opacity += 0.05f;
    }
}
