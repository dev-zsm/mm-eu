// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_FadeOut), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_osn.h"

void func_80000280(EnOsn* this) {
    s16 curFrame = this->skelAnime.curFrame;
    s16 endFrame = Animation_GetLastFrame(sAnimationInfo[this->animIndex].animation);

    if (curFrame == endFrame) {
        this->alpha -= 8;
        if (this->alpha < 8) {
            this->alpha = 0;
            Actor_Kill(&this->actor);
        }
    }
}
