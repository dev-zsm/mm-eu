// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_movebg.h"

void ref_func_80A2A688(BgDblueMovebg* this, PlayState* play) {
    this->unk_180--;
    if (this->unk_180 <= 0) {
        CutsceneManager_Stop(this->csIdList[0]);
    }

    if (Math_StepToF(&this->dyna.actor.world.pos.y, this->dyna.actor.home.pos.y - 60.0f, 2.0f) &&
        (this->unk_180 <= 0)) {
        Actor_Kill(&this->dyna.actor);
    }
}
