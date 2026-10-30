// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_Init(GfxPrint *this) {
    this->flags &= ~GFXPRINT_FLAG_OPEN;
    this->callback = GfxPrint_Callback;
    this->flags &= ~GFXPRINT_FLAG_1;
    this->flags &= ~GFXPRINT_FLAG_2;
    this->flags |= GFXPRINT_FLAG_4;
    this->dList = NULL;
    this->posX = 0;
    this->posY = 0;
    this->baseX = 0;
    this->baseY = 0;
    this->color.rgba = 0;
    this->flags |= GFXPRINT_FLAG_8;
}
