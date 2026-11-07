#include "types.h"
#include "m2c_compat.h"
typedef struct { u8 pad0[0x18875]; u8 f75; u8 pad1[4]; u16 f7A; u8 pad2[3]; u8 f7F; } PS;
extern struct { u8 pad0[0x3F4A]; u16 f3F4A; u8 pad1[9]; u8 f3F55; } D_801E6EF0;

void func_80001AD4(u8 *a, PS *play) {
    play->f7A = 0x6400;
    D_801E6EF0.f3F4A = 0xFFF5;
    play->f75 = 0x14;
    play->f7F = 0x40;
    D_801E6EF0.f3F55 = 2;
}
