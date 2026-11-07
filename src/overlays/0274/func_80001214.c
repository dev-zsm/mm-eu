#include "types.h"
typedef struct { u8 pad0[0x284]; void* a284; u8 pad1[0x14]; s16 a29C; } A;
extern u8 D_809AA720[];
void func_800B87A0(s32, s32, s32, f32, f32);
void func_80001214(A *this, s32 play) {
    func_800B87A0((s32)this, play, 0x50, 300.0f, 300.0f);
    this->a29C = 1;
    this->a284 = D_809AA720;
}
