#include "types.h"
typedef struct { u8 pad0[0x14]; s32 a14; } X;
typedef struct { u8 pad0[0x144]; s32 a144; u8 pad1[0x8]; s32 a150; u8 pad2[0xB8]; s32 a20C; } A;
extern X *D_80888628[];
void func_801377D0();
void func_800032A0(A *this) {
    this->a144 = 0xB;
    this->a20C = 5;
    func_801377D0((u8 *)this + 0x1A4, D_80888628[this->a150]->a14, this);
}
