#include "types.h"
typedef struct { u8 pad0[0x70]; f32 a70; u8 pad1[0xD8]; u8* a14C; u8 pad2[0xC]; f32 a15C; f32 a160; u8 pad3[0x24]; void* a188; } A;
extern u8 D_60010F4[];
extern u8 D_60039C4[];
extern u8 D_808EA14C[];
void func_80005A70(A *this) {
    if (this->a14C == D_60039C4 || this->a14C == D_60010F4) {
        this->a15C = 1.0f;
    }
    this->a188 = D_808EA14C;
    this->a160 = 0.0f;
    this->a70 = 0.0f;
}
