#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

extern u8 D_801C2660[];

Gfx* Gfx_SetupDL57_b(Gfx* gfx) {
    // one line: the ROM's scheduling depends on the whole command macro being emitted from a single source line
    do { Gfx* dst = gfx++; dst->w0 = 0xDE000000; dst->w1 = (u32)D_801C2660; } while (0);
    return gfx;
}
