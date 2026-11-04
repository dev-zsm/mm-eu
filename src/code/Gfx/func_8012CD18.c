// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_rcp.h"

Gfx* Gfx_SetupDL20_NoCD(Gfx* gfx) {
    gSPDisplayList(gfx++, gSetupDLs[SETUPDL_20]);
    gDPSetColorDither(gfx++, G_CD_DISABLE);
    return gfx;
}
