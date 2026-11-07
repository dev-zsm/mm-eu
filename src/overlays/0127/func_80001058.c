#include "types.h"
typedef struct { u8 pad0[0x116]; s16 a116; u8 pad1[0x374]; s32 a48C; } Q;
typedef struct { u8 pad0[0x116]; s16 a116; u8 pad1[0x374]; s32 a48C; u8 pad2[0x14]; Q* q; } A;
void func_800B844C();
void func_80001058(A *this, s32 b, u16 c) {
    func_800B844C(this, b, this->q);
    this->a116 = 0;
    this->q->a116 = c;
    this->q->a48C = 2;
    this->a48C = 0;
}
