// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 DynaPoly_IsBgIdBgActor(s32);
u8 *DynaPoly_GetActor(s32, s32);

void DynaPoly_DeleteBgActor(s32 arg0, u8 *arg1, s32 arg2) {
    u8 *p;

    if (DynaPoly_IsBgIdBgActor(arg2) != 0) {
        p = DynaPoly_GetActor(arg0 + 0x830, arg2);
        if (p != NULL) {
            *(s32 *)(p + 0x144) = -1;
            *(s32 *)(arg1 + arg2 * 0x64 + 4) = 0;
            *(u16 *)((u8 *)((s32)arg1 + arg2 * 2) + 0x138C) |= 2;
        }
    }
}
