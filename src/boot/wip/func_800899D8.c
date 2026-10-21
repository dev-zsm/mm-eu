// FLAGS: -O2 -g0
#include "types.h"
typedef struct { u8 b[0x27]; } Entry;
u32 func_80091240(u32 size);
void func_800899D8(s32 count, u8 *buf) {
    Entry e;
    u8 *p;
    s32 i;
    e.b[0] = 0xFF; e.b[1] = 0x23; e.b[2] = 0x01; e.b[3] = 0x03; e.b[4] = 0xC0;
    e.b[5] = (u8)func_80091240(0x600);
    p = buf;
    if (count > 0) { for (i = 0; i < count; i++) { *p++ = 0; } }
    *(Entry *)p = e;
    p[0x27] = 0xFE;
}
