#include "types.h"
typedef struct { u8 pad0[0x32]; s16 unk32; u8 pad34[0x3C]; f32 unk70; u8 pad74[0x4A]; s16 unkBE; u8 pad[0x5F]; u8 unk11F; u8 pad120[0xE0]; void *unk200; u8 pad204[2]; s16 unk206; u8 pad208[0xB6]; u8 unk2BE; } A;
extern u8 D_80B47840;
void func_800014F4(A *a) {
    a->unk206 = 0;
    a->unk70 = 0.0f;
    a->unk32 = a->unkBE;
    a->unk11F = 0xFF;
    a->unk2BE &= 0xFFFE;
    a->unk200 = &D_80B47840;
}
