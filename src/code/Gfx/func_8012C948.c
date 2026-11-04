#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx D_801C20F0[];

Gfx *func_8012C948(Gfx *dl) {
    // one line: the ROM's scheduling depends on the body being emitted from a single source line (the empty if (0) is needed too)
    Gfx *g = dl++; g->w0 = 0xDE000000; g->w1 = (u32)D_801C20F0; if (0) { } return dl;
}
