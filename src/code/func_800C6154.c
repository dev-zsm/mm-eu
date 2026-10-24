// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 DynaPoly_IsBgIdBgActor(s32);
void func_800C6154(s32 arg0, u8 *arg1, s32 arg2) {
    u8 *p;
    if (DynaPoly_IsBgIdBgActor(arg2) != 0) {
        p = (u8 *)((s32)arg1 + arg2 * 2);
        *(u16 *)(p + 0x138C) &= ~8;
        *arg1 |= 1;
    }
}
