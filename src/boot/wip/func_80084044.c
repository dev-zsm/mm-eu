// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

typedef struct {
    u16 *fb;
    u16 w;
    u16 h;
    u16 yStart;
    u16 yEnd;
    u16 xStart;
    u16 xEnd;
    u16 foreColor;
    u16 backColor;
    u16 cursorX;
    u16 cursorY;
    u32 *font;
    u8 charW;
    u8 charH;
} FaultDrawer;

extern FaultDrawer *D_80096D80;

void FaultDrawer_DrawChar(u8 c) {
    s32 x;
    s32 y;
    u32 data;
    s32 mask;
    s32 mask0;
    s32 shift;
    u32 *dataPtr;
    u16 *fb;
    s32 cx;
    s32 cy;
    s32 ch = c;

    shift = (ch & 4) >> 2;
    dataPtr = &D_80096D80->font[(ch / 8) * 16 + shift];
    fb = D_80096D80->fb + D_80096D80->w * D_80096D80->cursorY + D_80096D80->cursorX;
    if (D_80096D80->cursorX < D_80096D80->xStart) {
        return;
    }
    if (D_80096D80->cursorX + D_80096D80->charW - 1 > D_80096D80->xEnd) {
        return;
    }
    if (D_80096D80->cursorY < D_80096D80->yStart) {
        return;
    }
    if (D_80096D80->cursorY + D_80096D80->charH - 1 > D_80096D80->yEnd) {
        return;
    }
    mask0 = 0x10000000 << (ch % 4);
    for (y = 0; y < D_80096D80->charH; y++) {
        mask = mask0;
        data = *dataPtr;
        for (x = 0; x < D_80096D80->charW; x++) {
            if (mask & data) {
                fb[x] = D_80096D80->foreColor;
            } else if (D_80096D80->backColor & 1) {
                fb[x] = D_80096D80->backColor;
            }
            mask >>= 4;
        }
        fb += D_80096D80->w;
        dataPtr += 2;
    }
}
