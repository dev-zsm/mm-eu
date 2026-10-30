#include "types.h"

typedef struct { u8 pad0[0x70]; f32 unk70; u8 pad74[0x234]; void *unk2A8; u8 pad2AC[6]; s16 unk2B2; } A;
extern void func_800BE2EC();
extern u8 D_80897B74[];

void func_800014E4(A *a) {
    func_800BE2EC(a, (u8 *)a + 0x410);
    a->unk2B2 = 0;
    a->unk2A8 = D_80897B74;
    a->unk70 = 0.0f;
}
