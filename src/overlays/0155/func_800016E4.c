#include "types.h"
extern f32 D_8092199C;
extern u8 D_80920DC4[];
typedef struct { u8 pad0[0x5C]; f32 f; u8 pad60[0xFC]; u8 *p; } S;
void func_800016E4(S *a) {
    a->f = D_8092199C;
    a->p = D_80920DC4;
}
