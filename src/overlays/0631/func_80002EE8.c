#include "types.h"
typedef struct { u8 p0[4]; s32 flags; u8 p1[0x70 - 8]; f32 f70; u8 p2[0x284 - 0x74]; void *fn; u32 a288; u8 p3[0x2A4 - 0x28C]; s32 a2A4; u8 p4[0x2AE - 0x2A8]; s8 a2AE; u8 p5[5]; s16 a2B4; } T;
extern u8 D_80BF2F60[];
void func_80002EE8(T *this) {
    this->flags |= 0x08000000;
    this->a2AE = 0;
    this->a2A4 = 0;
    this->flags &= ~1;
    this->a2B4 = 0xE;
    this->fn = D_80BF2F60;
    this->f70 = 0.0f;
}
