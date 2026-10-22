// FLAGS: -O2 -g0 -mips2 -trapuv
#include "types.h"

typedef struct {
    u16 *buf;
    u16 w;
    u16 h;
} Fb;

extern Fb *D_80096D80;

extern void osWritebackDCacheAll(void);

void FaultDrawer_DrawRecImpl(s32 x0, s32 y0, s32 x1, s32 y1, u16 color) {
    s32 cw;
    s32 ch;
    s32 i;
    s32 j;
    s32 k;
    u16 *v;

    cw = D_80096D80->w - x0;
    ch = D_80096D80->h - y0;
    if (cw <= 0 || ch <= 0) {
        return;
    }
    if (cw > x1 - x0 + 1) {
        cw = x1 - x0 + 1;
    }
    if (ch > y1 - y0 + 1) {
        ch = y1 - y0 + 1;
    }
    v = D_80096D80->buf + D_80096D80->w * y0 + x0;
    for (i = 0; i < ch; i++) {
        j = 0;
        if (cw > 0) {
            k = cw & 3;
            for (j = 0; j < k; j++) {
                v[j] = color;
            }
            v += k;
            for (; j < cw; j += 4) {
                v[0] = color;
                v[1] = color;
                v[2] = color;
                v[3] = color;
                v += 4;
            }
        }
        v += D_80096D80->w - cw;
    }    osWritebackDCacheAll();
}
