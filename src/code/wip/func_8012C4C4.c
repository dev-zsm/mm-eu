#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C2570[];

// One-line macros: the ROM's scheduling depends on each command being emitted from a single source line.
#define DISPLAY_LIST_CMD(pkt, dl) { Gfx *_g = (pkt); _g->w0 = 0xDE000000; _g->w1 = (u32)(dl); }
#define GEOMETRY_MODE_CMD(pkt) { Gfx *_g = (pkt); _g->w0 = 0xE3001801; _g->w1 = 0xC0; }

Gfx *Gfx_SetupDL52_NoCD(Gfx *gfx) {
    DISPLAY_LIST_CMD(gfx++, D_801C2570);
    GEOMETRY_MODE_CMD(gfx++);
    return gfx;
}
