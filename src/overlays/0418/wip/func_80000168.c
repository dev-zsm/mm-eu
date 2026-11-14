// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_TurnAround), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_osn.h"

void func_80000168(EnOsn* this) {
    s16 curFrame = this->skelAnime.curFrame;
    s16 endFrame = Animation_GetLastFrame(sAnimationInfo[this->animIndex].animation);

    if ((this->animIndex == OSN_ANIM_TURN_AROUND_START) && (curFrame == endFrame)) {
        this->animIndex = OSN_ANIM_TURN_AROUND_LOOP;
        Actor_ChangeAnimationByInfo(&this->skelAnime, sAnimationInfo, OSN_ANIM_TURN_AROUND_LOOP);
    }
}
