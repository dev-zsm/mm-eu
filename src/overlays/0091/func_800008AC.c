#include "types.h"
typedef struct { u8 pad0[0x230]; void* a230; u8 pad1[0x2]; s16 a236; u8 pad2[0x4]; s16 a23C; u8 pad3[0x2]; f32 a240; } A;
extern u8 D_808AFCA8[];
s16 func_800B6AB0();
void func_800008AC(A *this) {
    this->a240 = 6.0f;
    this->a23C = func_800B6AB0(this, (u8 *)this + 8);
    this->a236 = 1;
    this->a230 = D_808AFCA8;
}
