// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_vismono.h"

void VisMono_Draw(VisMono* this, Gfx** gfxP) {
    Gfx* gfx = *gfxP;
    u16* tlut;
    Gfx* dList;
    Gfx* dListEnd;

    if (this->tlut) {
        tlut = this->tlut;
    } else {
        tlut = Gfx_Alloc(&gfx, 256 * G_IM_SIZ_16b_BYTES);
        VisMono_DesaturateTLUT(tlut);
    }

    if (this->dList) {
        dList = this->dList;
    } else {
        dList = Gfx_Alloc(&gfx, VISMONO_DLSIZE * sizeof(Gfx));
        dListEnd = VisMono_DesaturateDList(dList);
    }

    gDPPipeSync(gfx++);

    if (this->vis.scissorType == VIS_SETSCISSOR) {
        gSPDisplayList(gfx++, ref_D_0E000000.setScissor);
    }

    gDPSetColor(gfx++, G_SETPRIMCOLOR, this->vis.primColor.rgba);
    gDPSetColor(gfx++, G_SETENVCOLOR, this->vis.envColor.rgba);

    gDPLoadTLUT_pal256(gfx++, tlut);

    gSPDisplayList(gfx++, dList);

    gDPPipeSync(gfx++);

    *gfxP = gfx;
}
