#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern Gfx D_801C2000[];

Gfx* Gfx_SetupDL23(Gfx* gfx) {
    Gfx* dl;

    // do-while(0) is needed: it changes register allocation (extra move of the return value)
    // one line: the ROM's scheduling depends on the command being emitted from a single source line
    do { dl = gfx++; dl->w0 = 0xDE000000; dl->w1 = (u32)D_801C2000; } while (0);
    return gfx;
}
