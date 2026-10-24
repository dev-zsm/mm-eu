#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx D_801C1BB0[];

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define DISPLAY_LIST_CMD(pkt, dl) do { Gfx *_g = (pkt); _g->w0 = 0xDE000000; _g->w1 = (u32)(dl); } while (0)

Gfx *Gfx_SetupDLImpl(Gfx *gfx, s32 idx) {
    DISPLAY_LIST_CMD(gfx++, &D_801C1BB0[idx * 6]);
    return gfx;
}
