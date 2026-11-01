#include "types.h"
typedef struct { u8 pad[0x5C]; f32 unk5C; u8 pad60[0xFC]; void *unk15C; s16 unk160; } A;
extern f32 D_809219A8;
extern u8 D_80920F78[];
void func_80001890(A *a0) { a0->unk5C = D_809219A8; a0->unk160 = 6; a0->unk15C = D_80920F78; }
