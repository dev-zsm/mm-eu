#include "types.h"
typedef struct { u8 p0[0x92]; s16 a92; u8 p1[0x284 - 0x94]; void *fn; u8 p2[0x2A4 - 0x288]; s16 a2A4; u8 p3[0x2C0 - 0x2A6]; s16 a2C0; } T;
extern u8 D_80BE8D4C[];
void func_80BE85C4(T *, s32, f32);
void func_80000A34(T *this) {
    this->a2A4 = this->a92;
    func_80BE85C4(this, 1, 1.0f);
    this->a2C0 = 1;
    this->fn = D_80BE8D4C;
}
