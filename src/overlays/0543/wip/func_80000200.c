#include "types.h"

typedef struct {
    u8 pad0[0xC];
    u16 a;
    u8 pad1[0x16 - 0xE];
    u16 b;
} G;

typedef struct {
    u8 pad0[0x32];
    u16 v;
} H;

extern G D_801E6EF0;
extern H *D_801EB7E0;

void func_80000200(void) {
    u16 t = D_801E6EF0.a;
    D_801E6EF0.a = D_801EB7E0->v + t;
    D_801E6EF0.a = D_801E6EF0.b + D_801E6EF0.a;
}
