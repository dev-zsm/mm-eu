#include "types.h"

typedef struct {
    u8 pad0[0x138C];
    u16 flags[50];
} DynaCtx;

extern void BgActor_SetActor(u8 *a, s32 b, s32 c);

s32 DynaPoly_SetBgActor(s32 arg0, DynaCtx *arg1, s32 arg2, s32 arg3) {
    s32 i;
    s32 found = 0;
    s32 pad;
    for (i = 0; i < 50; i++) {
        if (!(arg1->flags[i] & 1)) {
            arg1->flags[i] |= 1;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        return 0x32;
    }
    BgActor_SetActor((u8 *)arg1 + 4 + i * 0x64, arg2, arg3);
    *(u8 *)arg1 |= 1;
    arg1->flags[i] &= ~2;
    return i;
}
