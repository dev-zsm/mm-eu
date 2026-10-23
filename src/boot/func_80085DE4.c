// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[8];
    u16 posX;
    u16 posY;
    u16 baseX;
    u8 pad1;
    u8 flags;
} GfxPrint;

extern void GfxPrint_PrintCharImpl(GfxPrint *this, u8 c);

void GfxPrint_PrintChar(GfxPrint *this, u8 c) {
    if (c == ' ') {
        this->posX += 0x20;
    } else if (c > 0x20 && c < 0x7F) {
        GfxPrint_PrintCharImpl(this, c);
    } else if (c >= 0xA0 && c < 0xE0) {
        if (this->flags & 1) {
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
                this->flags |= 1;
                break;
            case 0x8C:
                this->flags &= ~1;
                break;
            case 0x8B:
                this->flags |= 2;
                this->flags |= 8;
                break;
            case 0x8A:
                this->flags &= ~2;
                this->flags |= 8;
                break;
            case 0x8E:
            default:
                break;
        }
    }
}
