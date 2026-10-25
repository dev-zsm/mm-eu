#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    char pad0[0x2A0];
    Gfx* dlHead;
} GraphicsContext;

extern Gfx D_801C2450[];

void func_8012C9E8(GraphicsContext* gfxCtx) {
    Gfx* dl = gfxCtx->dlHead++;

    // one line: the ROM's scheduling depends on the command being emitted from a single source line
    dl->w0 = 0xDE000000; dl->w1 = (u32)D_801C2450;
}
