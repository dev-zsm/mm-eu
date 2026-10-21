// FLAGS: -O2 -g0
#include "types.h"
typedef struct { u8 a, b, c, d, e, f; u8 pad[0x21]; } Entry;
u32 func_80091240(u32 size);
void func_800899D8(s32 count, u8 *buf) {
    u8 *p;
    Entry e;
    s32 i;
    p = buf;
    e.a = 0xFF;
    e.b = 0x23;
    e.c = 0x01;
    e.d = 0x03;
    e.e = 0xC0;
    e.f = (u8)(func_80091240(0x600) | 0xC000);
    if (count != 0) { for (i = 0; i < count; i++) { *p++ = 0; } }
    *(Entry *)p = e;
    p += 0x27;
    *p = 0xFE;
}
