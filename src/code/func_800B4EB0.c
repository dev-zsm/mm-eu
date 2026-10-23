#include "types.h"

void Attention_SetReticlePos(u8 *a0, s32 a1, f32 a2, f32 a3, f32 a4) {
    u8 *v0 = (u8 *)((u32)a0 + a1 * 20);
    *(f32 *)(v0 + 0x50) = a2;
    *(f32 *)(v0 + 0x54) = a3;
    *(f32 *)(v0 + 0x58) = a4;
    *(f32 *)(v0 + 0x5C) = *(f32 *)(a0 + 0x44);
}
