// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ObjHunsui_Draw(Actor* thisx, PlayState* play) {
    ObjHunsui* this = (ObjHunsui*)thisx;

    if (this->unk_172 & 0x10) {
        f32 temp_f8 = (this->dyna.actor.world.pos.y - this->dyna.actor.home.pos.y) / 800.0f;

        Audio_PlaySfx_AtPosWithFreq(&this->dyna.actor.projectedPos, NA_SE_EV_WATER_PILLAR - SFX_FLAG, 1.0f + temp_f8);
    }

    if (!(this->unk_172 & 2)) {
        AnimatedMat_Draw(play, ref_D_80B9DED0);
        Gfx_DrawDListXlu(play, object_hunsui_DL_000220);
    }
}
