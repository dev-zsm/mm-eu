#include "types.h"
typedef struct { u8 pad0[0x32]; s16 a32; u8 pad1[0x8A]; s16 aBE; u8 pad2[0x1E8]; void* a2A8; u8 pad3[0xE9]; u8 a395; } A;
extern u8 D_60039C4[];
extern u8 D_8086BF3C[];
void func_801378E0();
void func_80002A38(A *thisx) {
    A *this = thisx;
    func_801378E0((u8 *)this + 0x144, D_60039C4, this);
    this->a395 |= 1;
    this->a32 = this->aBE;
    this->a2A8 = D_8086BF3C;
}
