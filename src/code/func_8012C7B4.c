#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C2930[];

// One-line macro: the ROM's scheduling depends on the command being emitted from a single source line.
#define DISPLAY_LIST_CMD(pkt, dl) do { Gfx *_g = (pkt); _g->w0 = 0xDE000000; _g->w1 = (u32)(dl); } while (0)

Gfx *func_8012C7B4(Gfx *gfx) {
    DISPLAY_LIST_CMD(gfx++, D_801C2930);
    return gfx;
}
