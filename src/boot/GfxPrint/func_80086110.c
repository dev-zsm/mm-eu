// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

Gfx *GfxPrint_Close(GfxPrint *this) {
    Gfx *dList = this->dList;

    this->dList = NULL;
    this->flags &= ~GFXPRINT_FLAG_OPEN;
    return dList;
}
