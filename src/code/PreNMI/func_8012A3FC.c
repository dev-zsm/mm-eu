// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_prenmi_ctx.h"

void PreNMI_Draw(PreNMIState* this) {
    GraphicsContext* gfxCtx = this->state.gfxCtx;

    ref_func_8012CF0C(gfxCtx, true, true, 0, 0, 0);

    OPEN_DISPS(gfxCtx);

    Gfx_SetupDL36_Opa(gfxCtx);

    gDPSetFillColor(POLY_OPA_DISP++, (GPACK_RGBA5551(255, 255, 255, 1) << 16) | GPACK_RGBA5551(255, 255, 255, 1));
    gDPFillRectangle(POLY_OPA_DISP++, 0, this->timer + 100, SCREEN_WIDTH - 1, this->timer + 100);

    CLOSE_DISPS(gfxCtx);
}
