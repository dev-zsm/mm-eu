// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    void *p0;
    u32 p4;
} Ctx;

s32 func_800928D0(void *a0, u32 a1, u8 *a2);
s32 func_800966E0(void *a0, u32 a1, s32 a2, u8 *a3);
s32 func_80089720(Ctx *a0, u8 *a1);

s32 func_8008EED0(Ctx *a0, u8 a1) {
    s32 err;
    u8 buf[8];
    s32 r;

    err = func_800928D0(a0->p0, a0->p4, &buf[7]);
    if (err != 0) {
        return err;
    }
    if (buf[7] & 0x2) {
        return 0xF;
    }
    *(u32 *)buf = 0x02000000;
    buf[2] = a1;
    err = func_800966E0(a0->p0, a0->p4, 0, buf);
    if (err != 0) {
        return err;
    }
    err = func_80089720(a0, &buf[7]);
    r = err;
    if (err & 0xFF00) {
        r = 5;
    }
    return r;
}
