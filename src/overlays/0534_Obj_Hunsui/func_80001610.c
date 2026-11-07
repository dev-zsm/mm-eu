// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ref_func_80B9DA60(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjHunsui* this = (ObjHunsui*)thisx;
    f32 temp;

    if (this->unk_172 & 0x10) {
        temp = 1.0f + ((this->unk_178 - 240.0f) / 270.0f);
        Audio_PlaySfx_AtPosWithFreq(&this->dyna.actor.projectedPos, NA_SE_EV_WATER_PILLAR - SFX_FLAG, 1.0f + temp);
    }

    if ((this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) && !(this->unk_172 & 2)) {
        if ((this->unk_160 == OBJHUNSUI_F000_6) || (this->unk_160 == OBJHUNSUI_F000_5)) {
            OPEN_DISPS(play->state.gfxCtx);

            gSPSegment(POLY_XLU_DISP++, 0x08,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, (play->gameplayFrames % 128) * -9, 0x20, 0x20, 1, 0,
                                        (play->gameplayFrames % 128) * -8, 0x20, 0x20));
            gSPSegment(POLY_XLU_DISP++, 0x09,
                       Gfx_TwoTexScroll(play->state.gfxCtx, 0, 0, (s32)this->unk_1AC, 0x20, 0x20, 1, 0,
                                        (s32)this->unk_1B0, 0x20, 0x20));

            CLOSE_DISPS(play->state.gfxCtx);
        } else {
            AnimatedMat_DrawXlu(play, ref_D_80B9DED4);
        }

        OPEN_DISPS(play->state.gfxCtx);

        gDPSetPrimColor(POLY_XLU_DISP++, 0, 0x7F, 255, 255, 255, 127);

        Gfx_DrawDListXlu(play, object_hunsui_DL_000EC0);

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
