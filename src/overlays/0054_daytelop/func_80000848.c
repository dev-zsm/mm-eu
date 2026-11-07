// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_daytelop.h"

void DayTelop_Main(GameState* thisx) {
    DayTelopState* this = (DayTelopState*)thisx;

    ref_func_8012CF0C(this->state.gfxCtx, true, true, 0, 0, 0);

    OPEN_DISPS(this->state.gfxCtx);
    gSPSegment(POLY_OPA_DISP++, 0x09, this->daytelopStaticFile);
    gSPSegment(POLY_OPA_DISP++, 0x0C, this->gameoverStaticFile);
    CLOSE_DISPS(this->state.gfxCtx);

    DayTelop_Draw(this);
    DayTelop_Update(this, &this->state);
}
