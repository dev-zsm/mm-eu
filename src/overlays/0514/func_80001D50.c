// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void BgIkanaRotaryroom_Draw(Actor* thisx, PlayState* play) {
    BgIkanaRotaryroom* this = (BgIkanaRotaryroom*)thisx;
    s32 param = BGIKANAROTARYROOM_GET_1(&this->dyna.actor);

    if (!param) {
        Gfx_DrawDListOpa(play, object_ikana_obj_DL_0048A0);
        Gfx_DrawDListXlu(play, object_ikana_obj_DL_004710);
    } else {
        AnimatedMat_Draw(play, this->unk_1FC);
        Gfx_DrawDListOpa(play, object_ikana_obj_DL_007448);
        Gfx_DrawDListXlu(play, object_ikana_obj_DL_007360);
    }
}
