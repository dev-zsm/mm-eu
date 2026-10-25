#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx D_801C2210[];

Gfx* func_8012C87C(Gfx* gfx) {
    // one line: the ROM's scheduling depends on the whole command (incl. the pointer bump) coming from a single source line
    do { Gfx* dl = gfx++; dl->w0 = 0xDE000000; dl->w1 = (u32)D_801C2210; } while (0);
    return gfx;
}
