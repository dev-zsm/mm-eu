// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

bool ref_func_808B751C(BgBreakwall* this, PlayState* play) {
    Actor_SetScale(&this->dyna.actor, 0.1f);

    if ((BGBREAKWALL_SWITCH_FLAG(&this->dyna.actor) != 0x7F) &&
        !Flags_GetSwitch(play, BGBREAKWALL_SWITCH_FLAG(&this->dyna.actor))) {
        return false;
    }

    ref_func_800FEA50(play);

    if (gSaveContext.save.isNight) {
        this->unk_15E = 0;
    } else {
        this->unk_15E = 255;
    }
    return true;
}
