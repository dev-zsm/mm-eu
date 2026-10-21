// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct Thing {
    void *ptr;
    s32 size;
    u8 pad8[4];
    u8 flags;
} Thing;

s32 func_800928D0(void *a, s32 b, void *c);
s32 func_8008F070(void *a, s32 b, s32 c, u8 *d);

s32 func_80089720(Thing *s0, u8 *a1) {
    u8 sp20[2];
    s32 ret;

    ret = func_800928D0(s0->ptr, s0->size, a1);
    if (ret != 0) {
        goto done;
    }
    if (a1[0] & 1) {
        ret = 0xF;
        goto done;
    }
    ret = func_8008F070(s0->ptr, s0->size, 0, sp20);
    if (ret != 0) {
        goto done;
    }
    s0->flags = sp20[0] & 7;
    if (sp20[0] & 0x40) {
        ret = 0xF;
    } else {
        ret = sp20[1] << 8;
    }
done:
    return ret;
}
