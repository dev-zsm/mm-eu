#include "types.h"
typedef struct { u16 w; u16 h; u8 pad[0x14]; u8 *buf; } S;
extern void PreRender_AntiAliasFilterPixel(S *, s32, s32);
void PreRender_AntiAliasFilter(S *a0) {
    s32 x;
    s32 y;
    s32 t;
    y = 0;
    if (a0->h > 0) {
        do {
            x = 0;
            if (a0->w > 0) {
                do {
                    t = (a0->buf[x + y * a0->w] >> 5) + 1;
                    if (t != 8) {
                        PreRender_AntiAliasFilterPixel(a0, x, y);
                    }
                    x++;
                } while (x < a0->w);
            }
            y++;
        } while (y < a0->h);
    }
}
