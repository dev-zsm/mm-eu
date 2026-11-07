#include "types.h"
typedef struct { u8 pad0[0x70]; f32 a70; u8 pad1[0x234]; void* a2A8; u8 pad2[0xAC]; s16 a358; u8 pad3[0x12]; f32 a36C; } A;
extern u8 D_8098CA20[];
void func_8098B264();
void func_80001A18(A *this) {
    func_8098B264(this, 7);
    this->a358 = 0xA;
    this->a2A8 = D_8098CA20;
    this->a70 = 0.0f;
    this->a36C = 0.0f;
}
