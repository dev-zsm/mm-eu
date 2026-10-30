#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 h1C; u8 pad1[0x70-0x1E]; f32 f70; u8 pad2[0x390-0x74]; void *p390; u8 pad3[0x3C8-0x394]; s16 h3C8; } A;
extern u8 D_80A21C9C;
extern s16 D_80A221C8[];
void func_80000A30(A *a) {
    a->p390 = &D_80A21C9C;
    a->h3C8 = D_80A221C8[(a->h1C >> 10) & 7];
    a->f70 = 0.0f;
}
