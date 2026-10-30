// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_SetBasePosPx(GfxPrint *this, s32 x, s32 y) {
    this->baseX = x << 2;
    this->baseY = y << 2;
}
