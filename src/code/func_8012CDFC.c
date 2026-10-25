#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

typedef struct {
    u8 pad0[0x2C0];
    Gfx* polyXlu;
} GraphicsContext;

extern u8 D_801C20C0[];

void Gfx_SetupDL27_Xlu(GraphicsContext* ctx) {
    Gfx* dl = ctx->polyXlu++;

    // one line: the ROM's scheduling depends on the command being emitted from a single source line
    dl->w0 = 0xDE000000; dl->w1 = (u32)D_801C20C0;
}
