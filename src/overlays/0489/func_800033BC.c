#include "types.h"

typedef struct { u8 pad[0x1C]; s16 unk1C; } A;
extern void (*D_80B33A18[])();

void func_800033BC(A *a0) {
    D_80B33A18[(a0->unk1C >> 4) & 0xF]();
}
