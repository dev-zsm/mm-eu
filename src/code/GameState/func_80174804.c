#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;
typedef struct {
    u8 pad0[0x2A0];
    Gfx *a;
    u8 pad1[0xC];
    Gfx *b;
    u8 pad2[0xC];
    Gfx *c;
    u8 pad3[8];
    u32 fb;
} G;
void GameState_SetFrameBuffer(G *g) {
    Gfx *p;
    p = g->b++;
    p->w1 = 0;
    p->w0 = 0xDB060000;
    p = g->b++;
    // one line: the ROM's scheduling depends on these stores sharing a single source line
    do { p->w0 = 0xDB06003C; p->w1 = g->fb; p = g->c++; p->w1 = 0; p->w0 = 0xDB060000; p = g->c++; } while (0);
    p->w0 = 0xDB06003C;
    p->w1 = g->fb;
    p = g->a++;
    p->w1 = 0;
    p->w0 = 0xDB060000;
    p = g->a++;
    p->w0 = 0xDB06003C;
    p->w1 = g->fb;
}
