#include "gfxprint.h"

void GfxPrint_Open(GfxPrint *this, Gfx *dList) {
    if (!(this->flags & GFXPRINT_FLAG_OPEN)) {
        this->flags |= GFXPRINT_FLAG_OPEN;
        this->dList = dList;
        GfxPrint_Setup(this);
    }
}
