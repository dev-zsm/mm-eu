// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

void ref_func_808B7D34(Actor* thisx, PlayState* play) {
    BgBreakwall* this = (BgBreakwall*)thisx;
    s32 sp48;
    s32 tempA;
    s32 tempB;
    s32 tempC;

    OPEN_DISPS(play->state.gfxCtx);

    sp48 = 255 - this->unk_15E;

    tempA = (((sp48 * 245) + (this->unk_15E * 255)) & 0xFF00) >> 8;
    tempB = (((sp48 * 145) + (this->unk_15E * 85)) & 0xFF00) >> 8;
    tempC = (((sp48 * 135) + (this->unk_15E * 55)) & 0xFF00) >> 8;

    gSPSegment(POLY_XLU_DISP++, 0x09, Gfx_PrimColor(play->state.gfxCtx, 255, 255, tempA, tempB, tempC));

    tempA = (((sp48 * 255) + (this->unk_15E * 150)) & 0xFF00) >> 8;
    tempB = (((sp48 * 255) + (this->unk_15E * 100)) & 0xFF00) >> 8;
    tempC = (((sp48 * 255) + (this->unk_15E * 75)) & 0xFF00) >> 8;

    gSPSegment(POLY_XLU_DISP++, 0x0A, Gfx_PrimColor(play->state.gfxCtx, 255, tempA, tempA, tempB, tempC));

    tempA = (((sp48 * 185) + (this->unk_15E * 140)) & 0xFF00) >> 8;
    tempB = (((sp48 * 235) + (this->unk_15E * 45)) & 0xFF00) >> 8;

    gSPSegment(POLY_XLU_DISP++, 0x0B, Gfx_PrimColor(play->state.gfxCtx, 255, 255, 255, tempA, tempB));

    CLOSE_DISPS(play->state.gfxCtx);
}
