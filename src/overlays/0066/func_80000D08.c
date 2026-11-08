#include "types.h"
typedef struct { u8 pad0[0x32]; s16 a32; u8 pad1[0x34]; f32 a68; u8 pad2[0x4]; f32 a70; u8 pad3[0x4A]; s16 aBE; u8 pad4[0xC8]; void* a188; } A;
extern u8 D_6000EA4[];
extern u8 D_80874C8C[];
void func_801377D0();
void func_80000D08(A *thisx) {
    A *this = thisx;
    func_801377D0((u8 *)this + 0x144, D_6000EA4, this);
    this->a32 = this->aBE;
    this->a188 = D_80874C8C;
    this->a70 = 0.0f;
    this->a68 = 0.0f;
}
