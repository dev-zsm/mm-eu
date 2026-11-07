#include "types.h"
typedef struct { u8 pad0[0x10]; s32 a10; } X;
typedef struct { u8 pad0[0x144]; s32 a144; u8 pad1[0x8]; s32 a150; u8 pad2[0xB8]; s32 a20C; u8 pad3[0x4]; s32 a214; u8 pad4[0x164]; s16 a37C; } A;
extern X *D_80888628[];
void func_801377D0();
void func_80002F54(A *thisx) {
    A *this = thisx;
    this->a144 = 0xA;
    this->a214 = 0;
    this->a20C = 4;
    this->a37C = 0;
    func_801377D0((u8 *)this + 0x1A4, D_80888628[this->a150]->a10, this);
}
