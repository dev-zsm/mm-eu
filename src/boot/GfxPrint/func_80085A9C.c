// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_SetPos(GfxPrint *this, s32 x, s32 y) {
    GfxPrint_SetPosPx(this, x << 3, y << 3);
}
