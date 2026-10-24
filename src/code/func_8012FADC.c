// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern s32 D_801C3400[];
s32 func_8012FADC(u8 *arg0, s32 arg1, s16 arg2) {
    u8 *v = (u8 *)((s32)arg0 + arg1 * 0x44);
    s32 *a;
    s32 sz;
    s32 r;
    *(s16 *)(v + 0xC) = -arg2;
    *(s32 *)(v + 0x14) = 0;
    a = D_801C3400 + arg2 * 2;
    sz = a[1] - a[0];
    r = *(s32 *)(v + 0x10) + sz + 0xF;
    return r & ~0xF;
}
