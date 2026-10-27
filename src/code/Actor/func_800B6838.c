// FLAGS: -O2 -g3 -mips2
#include "types.h"

f32 Math_CosS(s16);
f32 Math_SinS(s16);

typedef struct {
    u8 pad0[0x30];
    s16 unk30;
    s16 unk32;
    u8 pad34[0x30];
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
} Actor30;

void Actor_UpdateVelocityWithoutGravity(Actor30 *this) {
    f32 sp24;

    sp24 = Math_CosS(this->unk30) * this->unk70;
    this->unk64 = Math_SinS(this->unk32) * sp24;
    this->unk68 = Math_SinS(this->unk30) * this->unk70;
    this->unk6C = Math_CosS(this->unk32) * sp24;
}
