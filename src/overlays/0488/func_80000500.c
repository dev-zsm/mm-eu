#include "types.h"

typedef struct {
    u8 pad[0x1C];
} E;

typedef struct {
    u8 pad[0xA4];
    s16 idx;
} A;

extern E D_801E6EF0[];

void func_80000500(A *a) {
    E *e = &D_801E6EF0[a->idx];

    *(u32 *)((u8 *)e + 0x10C) |= 4;
}
