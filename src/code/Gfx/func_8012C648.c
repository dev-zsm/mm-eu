#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;
extern u8 D_801C2090[];
Gfx *func_8012C648(Gfx *gfx) {
    u32 new_var;
    // one line: the ROM's scheduling depends on these stores sharing a single source line
    new_var = (u32) D_801C2090; { Gfx *_g = gfx++; _g->w0 = 0xDE000000; if (!gfx) { } _g->w1 = new_var;
    }
    ;
    if ((gfx && gfx) && gfx) {
    }
    return gfx;
}
