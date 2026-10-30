#include "types.h"
typedef struct { s32 pad0; s32 flags; u8 pad8[0x10E]; s16 u116; u8 pad118[7]; u8 u11F; } S;
void func_80001B38(S *a) {
    a->flags &= ~5;
    a->flags |= 9;
    a->flags |= 0x100000;
    a->u11F = 0xFF;
    a->u116 = 0;
}
