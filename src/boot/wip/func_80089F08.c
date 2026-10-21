// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u32 D_8009D2A0[];
extern u32 D_8009D2DC;
extern u8 D_8009D2E1;

typedef struct {
    u8 b[8];
} Ent8;

void func_80089F08(s32 arg0) {
    Ent8 buf;
    u32 *p;
    u32 *end;
    s32 i;

    end = &D_8009D2DC;
    p = D_8009D2A0;
    do {
        p++;
        p[-1] = 0;
    } while (p < end);

    D_8009D2A0[15] = 1;
    buf.b[0] = 0xFF;
    buf.b[1] = 1;
    buf.b[2] = 3;
    buf.b[3] = arg0 & 0xFF;
    buf.b[4] = 0xFF;
    buf.b[5] = 0xFF;
    buf.b[6] = 0xFF;
    buf.b[7] = 0xFF;

    p = D_8009D2A0;
    i = 0;
    if (D_8009D2E1 > 0) {
        do {
            i++;
            p += 2;
            *(Ent8 *)(p - 2) = buf;
        } while (i < D_8009D2E1);
    }
    *(u8 *)p = 0xFE;
}
