#include "types.h"
#include "m2c_compat.h"
typedef struct { u8 pad0[0x18875]; u8 f75; u8 pad1[4]; u16 f7A; u8 pad2[3]; u8 f7F; } PS;
extern u8 D_801EAE45;

void func_8000042C(PS *a, u16 b) {
    a->f7A = b;
    a->f7F = 0x40;
    D_801EAE45 = 0x40;
    a->f75 = 0x14;
}
