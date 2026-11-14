// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x70];
    f32 unk70;
    u8 pad74[0x284 - 0x74];
    u8 *unk284;
    u8 pad288[0x294 - 0x288];
    s16 unk294;
    u8 pad296[0x2B4 - 0x296];
    s16 unk2B4;
} Act;

extern u8 D_80BF201C[];

void func_800B8C4C();
void func_800BC8F4();

void func_80001F84(Act *this) {
    this->unk294 = 0x28;
    this->unk70 = 0.0f;
    func_800BC8F4(this, 0, 0x78, 0, 0x28);
    func_800B8C4C(this, 0x389E);
    this->unk2B4 = 0xA;
    this->unk284 = D_80BF201C;
}
