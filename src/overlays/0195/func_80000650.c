#include "types.h"
typedef struct { u8 pad0[0x68]; f32 a68; u8 pad1[0x4B4]; s16 a520; u8 pad2[0xA]; s16 a52C; } A;
f32 func_809590B4();
void func_80000650(A *this) {
    if (this->a520 == 0) {
        this->a52C = func_809590B4(this, 4);
    }
    this->a68 = -10.0f;
}
