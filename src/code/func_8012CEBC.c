#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx D_801C2630[];

void Gfx_SetupDL56_Ptr(Gfx** gfxp) {
    Gfx* gfx = *gfxp;
    Gfx* dl = gfx;

    // label: needed for the ROM's register allocation (copy of gfx kept in a second register)
dl_label:
    // one line: the ROM's scheduling depends on the command being emitted from a single source line
    dl->w0 = 0xDE000000; dl->w1 = (u32)D_801C2630;
    gfx++;
    *gfxp = gfx;
}
