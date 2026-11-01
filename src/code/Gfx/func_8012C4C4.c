#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;
extern u8 D_801C2570[];
Gfx *Gfx_SetupDL52_NoCD(Gfx *gfx) {
    // one line: the ROM's scheduling depends on these stores sharing a single source line
    do { { Gfx *_g = gfx++; _g->w0 = 0xDE000000; _g->w1 = (u32) D_801C2570; } if (1) { { Gfx *_g = gfx++; _g->w0 = 0xE3001801; ; _g->w1 = 0xC0; } ; } return gfx; } while (0);
}
