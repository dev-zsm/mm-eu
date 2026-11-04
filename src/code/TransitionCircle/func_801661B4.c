// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_circle.h"

void TransitionCircle_Draw(void* thisx, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    TransitionCircle* this = (TransitionCircle*)thisx;

    gDPPipeSync(gfx++);
    gSPDisplayList(gfx++, sTransCircleSetupDL);
    gDPSetPrimColor(gfx++, 0, this->color.a, this->color.r, this->color.g, this->color.b, 1);
    if (this->maskType == 0) {
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIM_LOD_FRAC, PRIMITIVE, 0, 0, 0, PRIMITIVE, TEXEL0, 0,
                          PRIM_LOD_FRAC, PRIMITIVE);
    } else {
        gDPSetCombineLERP(gfx++, 0, 0, 0, PRIMITIVE, 1, TEXEL0, PRIM_LOD_FRAC, PRIMITIVE, 0, 0, 0, PRIMITIVE, 1, TEXEL0,
                          PRIM_LOD_FRAC, PRIMITIVE);
    }
    TransitionCircle_LoadAndSetTexture(&gfx, this->texture, G_IM_FMT_I, 0, this->masks, this->maskt,
                                       this->referenceRadius);
    gDPPipeSync(gfx++);

    *gfxP = gfx;
}
