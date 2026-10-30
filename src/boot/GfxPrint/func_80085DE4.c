// FLAGS: -O2 -g0 -mips2
#include "gfxprint.h"

void GfxPrint_PrintChar(GfxPrint *this, u8 c) {
    if (c == ' ') {
        this->posX += 0x20;
    } else if (c > 0x20 && c < 0x7F) {
        GfxPrint_PrintCharImpl(this, c);
    } else if (c >= 0xA0 && c < 0xE0) {
        if (this->flags & GFXPRINT_FLAG_1) {
            if (c < 0xC0) {
                c -= 0x20;
            } else {
                c += 0x20;
            }
        }
        GfxPrint_PrintCharImpl(this, c);
    } else {
        switch (c) {
            case 0:
                break;
            case '\n':
                this->posY += 0x20;
                /* fallthrough */
            case '\r':
                this->posX = this->baseX;
                break;
            case '\t':
                do {
                    GfxPrint_PrintCharImpl(this, ' ');
                } while ((this->posX - this->baseX) % 0x100);
                break;
            case 0x8D:
                this->flags |= GFXPRINT_FLAG_1;
                break;
            case 0x8C:
                this->flags &= ~GFXPRINT_FLAG_1;
                break;
            case 0x8B:
                this->flags |= GFXPRINT_FLAG_2;
                this->flags |= GFXPRINT_FLAG_8;
                break;
            case 0x8A:
                this->flags &= ~GFXPRINT_FLAG_2;
                this->flags |= GFXPRINT_FLAG_8;
                break;
            case 0x8E:
            default:
                break;
        }
    }
}
