#include "types.h"
typedef struct { u8 pad0[0x70]; f32 a70; f32 a74; u8 pad1[0x18]; u16 a90; u8 pad2[0x1B6]; void* a248; u8 a24C; u8 a24D; } A;
extern u8 D_808BEFBC[];
void func_80000674(A *this) {
    this->a24C = 0xFF;
    this->a24D = 1;
    this->a90 &= 0xFFFE;
    this->a248 = D_808BEFBC;
    this->a70 = 5.0f;
    this->a74 = -1.0f;
}
