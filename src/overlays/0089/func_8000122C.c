#include "types.h"
typedef struct { u8 pad0[0x30]; s16 unk30; u8 pad1[0x3E]; f32 unk70; u8 pad2[0x15C]; void *unk1D0; } A;
extern u8 D_808AD290[];
void func_8000122C(A *a) {
    a->unk70 = 0.0f;
    a->unk30 = 0x4000;
    a->unk1D0 = D_808AD290;
}
