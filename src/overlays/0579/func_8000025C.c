// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_doukutu.h"

void BgIknvDoukutu_Cleanse(BgIknvDoukutu* this, PlayState* play) {
    if (this->opacity >= 0.05f) {
        this->opacity -= 0.05f;
    } else {
        this->actionFunc = BgIknvDoukutu_DoNothing;
        this->dyna.actor.draw = BgIknvDoukutu_DrawPurified;
    }
    play->envCtx.lightSettingOverride = 25;
}
