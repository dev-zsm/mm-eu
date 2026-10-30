// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_SetPosPx(GfxPrint *this, s32 x, s32 y) {
    this->posX = this->baseX + (x << 2);
    this->posY = this->baseY + (y << 2);
}
