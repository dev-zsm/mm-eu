#include "types.h"

typedef struct { u8 pad0[0x1C]; s16 unk1C; } A;
extern u8 D_808FD358[];

void func_800003FC(u8 *a, s32 b) {
    u8 *p = &D_808FD358[((((A *)a)->unk1C >> 4) & 0xF) * 3];
    a[0x1C5] = p[0];
    a[0x1C6] = p[1];
    a[0x1C7] = p[2];
}
