#include "types.h"
typedef struct { u8 pad0[0x70]; f32 unk70; u8 pad1[0x114]; void *unk188; u8 pad2[4]; s16 unk190; } A;
extern u8 D_8087990C[];
void func_80000AD8(A *a) {
    a->unk70 = 0.0f;
    a->unk190 = 0xF;
    a->unk188 = D_8087990C;
}
