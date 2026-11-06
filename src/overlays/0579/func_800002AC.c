// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_doukutu.h"

void BgIknvDoukutu_Cursed(BgIknvDoukutu* this, PlayState* play) {
    play->envCtx.lightSettingOverride = 24;
    if (Cutscene_IsCueInChannel(play, this->cueType) &&
        (play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id == 2)) {
        this->actionFunc = BgIknvDoukutu_Cleanse;
        this->dyna.actor.draw = BgIknvDoukutu_DrawCleansing;
    }
}
