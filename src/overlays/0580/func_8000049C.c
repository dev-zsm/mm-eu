// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_iknv_obj.h"

void ref_func_80BD7F4C(BgIknvObj* this, PlayState* play) {
    if (CURRENT_TIME > CLOCK_TIME(19, 30)) {
        this->actionFunc = ref_func_80BD7ED8;
    }
    if ((this->dyna.actor.home.rot.x == 1) && !CHECK_WEEKEVENTREG(WEEKEVENTREG_58_80)) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        this->dyna.actor.home.rot.x = 0;
    }
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
}
