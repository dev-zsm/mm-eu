#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C27E0[];

// One-line macros: the ROM's scheduling depends on each command being emitted from a single source line.
#define GSET_DL(pkt, dl) { Gfx *_g = (pkt); _g->w0 = 0xDE000000; _g->w1 = (u32)(dl); }
#define GSET_CMD(pkt, c0, c1) { Gfx *_g = (pkt); _g->w1 = (c1); _g->w0 = (c0); }

Gfx *Gfx_SetupDL65_NoCD(Gfx *gfx) {
    GSET_DL(gfx++, D_801C27E0);
    GSET_CMD(gfx++, 0xE3001801, 0xC0);
    return gfx;
}
