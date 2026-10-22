// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_8009D2E1;
extern u8 D_8009D2A0[];

typedef struct {
    u8 b[8];
} Ent8;

typedef struct {
    u16 h0;
    u8 b2;
    u8 b3;
} Out4;

void __osContGetInitData(u8 *arg0, Out4 *arg1) {
    Ent8 buf;
    Ent8 *src;
    Out4 *out;
    s32 i;
    s32 flags;
    s32 t;

    flags = 0;
    i = 0;
    src = (Ent8 *)D_8009D2A0;
    out = arg1;
    if (D_8009D2E1 > 0) {
        do {
            buf = *src;
            src++;
            t = (buf.b[2] & 0xC0) >> 4;
            out->b3 = t;
            if ((t & 0xFF) == 0) {
                out->h0 = (buf.b[5] << 8) | buf.b[4];
                flags = (flags | (1 << i)) & 0xFF;
                out->b2 = buf.b[6];
            }
            i++;
            out++;
        } while (i < D_8009D2E1);
    }
    *arg0 = flags;
}
