// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_SetColor(GfxPrint *this, u32 r, u32 g, u32 b, u32 a) {
    Gfx *dl;

    this->color.c.r = r;
    this->color.c.g = g;
    this->color.c.b = b;
    this->color.c.a = a;
    dl = this->dList++;
    dl->w0 = 0xE7000000;
    dl->w1 = 0;
    dl = this->dList++;
    dl->w0 = 0xFA000000;
    dl->w1 = this->color.rgba;
}
