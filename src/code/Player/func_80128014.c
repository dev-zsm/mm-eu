// FLAGS: -O2 -g3 -mips2
#include "types.h"
void Math_Vec3f_Copy(u8 *, void *);
extern u8 D_801C9EE0[];
void func_80128014(u8 *p, s32 n, void *a) {
    s32 i;
    for (i = 0; i < n; i++) {
        Math_Vec3f_Copy(p, a);
        Math_Vec3f_Copy(p + 0xC, D_801C9EE0);
        p += 0x1C;
        *(s16 *)(p - 4) = 0;
        *(s16 *)(p - 2) = 0;
    }
}
