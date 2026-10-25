#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2A0];
    Gfx* p;
} GfxCtx;

extern Gfx D_801C2390[];

void func_8012CD84(GfxCtx* gfxCtx) {
    Gfx* dl = gfxCtx->p++;

    // one line: the ROM's scheduling depends on the command being emitted from a single source line
    dl->w0 = 0xDE000000; dl->w1 = (u32)D_801C2390;
}
