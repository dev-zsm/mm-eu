#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C2870[];

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define GFX_CMD(gfx, cmd0, cmd1) { Gfx *_g = (gfx); _g->w0 = (cmd0); _g->w1 = (u32)(cmd1); (gfx)++; }

Gfx *Gfx_SetupDL68_NoCD(Gfx *gfx) {
    GFX_CMD(gfx, 0xDE000000, D_801C2870);
    GFX_CMD(gfx, 0xE3001801, 0xC0);
    return gfx;
}
