#include "types.h"
typedef struct { u8 pad0[0x1C]; s16 unk1C; u8 pad1E[0x52]; f32 unk70; u8 pad74[0x42C]; void *unk4A0; u8 pad4A4[0x3E]; s16 unk4E2; } A;
extern u8 D_80A0377C[];
extern s16 D_80A03F14[];
void func_80000FC0(A *a0) {
    a0->unk4A0 = D_80A0377C;
    a0->unk4E2 = D_80A03F14[(a0->unk1C >> 10) & 7];
    a0->unk70 = 0.0f;
}
