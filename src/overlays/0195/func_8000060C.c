#include "types.h"
typedef struct { u8 pad0[0x28]; f32 a28; u8 pad1[0x5C]; f32 a88; u8 pad2[0x4A0]; s16 a52C; u8 pad3[0xA]; f32 a538; } A;
f32 func_809590B4();
void func_8000060C(A *this) {
    this->a28 = this->a538 + this->a88;
    this->a52C = func_809590B4(this, 3);
}
