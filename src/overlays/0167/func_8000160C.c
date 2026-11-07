#include "types.h"
typedef struct { u8 pad0[0x258]; u8 a258; u8 pad1[0x14B]; u16 a3A4; u8 pad2[0x42]; s32 a3E8; } A;
void func_80932B44();
s32 func_8000160C(A *this, s32 play) {
    if (this->a258 != 6 && this->a3E8 == 0xC) {
        this->a3A4 &= 0xDFFF;
        func_80932B44(this, play, 8);
    }
    return 1;
}
