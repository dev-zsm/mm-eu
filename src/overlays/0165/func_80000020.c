#include "types.h"
typedef struct { f32 x, y, z; } V;
typedef struct A { u8 pad0[0x1C]; s16 unk1C; u8 pad1E[6]; V unk24; u8 pad30[0xF0]; struct A *unk120; } A;
typedef struct { u8 pad0[0x1CCC]; A *unk1CCC; } G;
void func_80000020(A *a0, G *a1) {
    A *v;
    if (a0->unk1C == 1) {
        v = a0->unk120;
    } else {
        v = a1->unk1CCC;
    }
    a0->unk24 = v->unk24;
}
