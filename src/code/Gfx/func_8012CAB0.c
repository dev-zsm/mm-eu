#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;
extern u8 D_801C2300[];
Gfx *Gfx_SetupDL39(Gfx *gfx) {
    u8 *new_var;
    // one line: the ROM's scheduling depends on these stores sharing a single source line
    { Gfx *_g = gfx++; _g->w0 = 0xDE000000; new_var = D_801C2300; _g->w1 = (u32) new_var;
    do { } while (0);
    }
    ;
    return gfx;
}
