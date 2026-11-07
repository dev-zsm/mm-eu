#include "types.h"
typedef struct { u8 pad0[0x32]; s16 a32; u8 pad1[0x8A]; s16 aBE; u8 pad2[0x170]; void* a230; u8 pad3[0x8]; s16 a23C; u8 pad4[0x2]; f32 a240; } A;
extern u8 D_808AFB88[];
s16 func_800B6AB0();
void func_80000790(A *this) {
    this->a32 = this->aBE;
    this->a240 = 0.0f;
    this->a23C = func_800B6AB0(this, (u8 *)this + 8);
    this->a230 = D_808AFB88;
}
