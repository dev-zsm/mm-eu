#include "types.h"
typedef struct { u8 pad0[0xC]; f32 aC; u8 pad1[0x18]; f32 a28; u8 pad2[0x90]; s16 aBC; u8 pad3[0xCA]; void* a188; u8 pad4[0x62]; s16 a1EE; } A;
extern u8 D_808F0C70[];
void func_800B6564(A *, f32);
void func_8000035C(A *this) {
    func_800B6564(this, 0);
    this->aBC = -0x4000;
    this->a1EE = 0;
    this->a28 = this->aC + 14.0f;
    this->a188 = D_808F0C70;
}
