#include "types.h"
typedef struct { u8 pad0[0x2A8]; void* a2A8; u8 pad1[0xAC]; s16 a358; u8 pad2[0x16]; f32 a370; u8 pad3[0x10]; f32 a384; } A;
extern u8 D_8098B4E4[];
void func_8098B264();
f32 func_8017A870(f32);
void func_800004D4(A *this) {
    func_8098B264(this, 2);
    this->a370 = func_8017A870(50.0f) + this->a384;
    this->a358 = 0;
    this->a2A8 = D_8098B4E4;
}
