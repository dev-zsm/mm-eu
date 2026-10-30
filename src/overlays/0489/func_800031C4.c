#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 unk1C; } A;
extern void (*D_80B339E0[])();
void func_800031C4(A *a0) {
    D_80B339E0[(a0->unk1C >> 4) & 0xF]();
}
