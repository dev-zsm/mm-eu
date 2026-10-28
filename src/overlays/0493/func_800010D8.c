#include "types.h"
typedef struct { u8 pad[0x144]; void *f; u8 pad2[0x740-0x148]; f32 g; } A;
extern u8 D_80B41108[];
void func_800010D8(A *x, s32 y) { x->f = D_80B41108; x->g = 0.0f; }
