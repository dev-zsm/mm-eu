// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    s32 pad0;
    s32 unk4;
    s32 unk8;
    u8 pad0C[0x59];
    u8 unk65;
} SomeStruct;
s32 func_80093F40(s32 a0, s32 a1, s32 a2, u8 *a3, s32 sp10);
s32 func_80092DA0(SomeStruct *a0, u8 a1) {
    u8 buf[0x20]; u8 *p; s32 ret; u8 c; c = a1; p = buf;
    do { p += 4; p[-3] = c; p[-2] = c; p[-1] = c; p[-4] = c; } while (p != buf + 0x20);
    ret = func_80093F40(a0->unk4, a0->unk8, 0x400, p - 0x20, 0);
    if (ret == 0) { a0->unk65 = c; }
    return ret;
}
