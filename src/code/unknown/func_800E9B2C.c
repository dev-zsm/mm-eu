#include "types.h"

typedef struct { u8 r; u8 g; u8 b; u8 text[41]; } DbgLine;
extern s32 D_801BBBC0;
extern s16 D_801BBC2C;
extern DbgLine D_801EB800[];

void func_800E9B2C(u8 r, u8 g, u8 b, u8 *str) {
    DbgLine *line = &D_801EB800[D_801BBC2C];
    s16 i;
    u8 *dst;

    D_801BBBC0 |= 2;
    if (D_801BBC2C < 0x50) {
        line->r = r;
        line->g = g;
        line->b = b;
        i = 0;
        dst = line->text;
        if ((*dst++ = *str++) != 0) {
            do {
                if (i++ >= 0x29) break;
            } while ((*dst++ = *str++) != 0);
        }
        *dst = 0;
        D_801BBC2C++;
    }
}
