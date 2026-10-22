// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x30];
    s16 unk30;
    s16 unk32;
    u8 pad1[0x64 - 0x34];
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
} Actor68;

f32 Math_CosS(s16);
f32 Math_SinS(s16);

void Actor_UpdateVelocityWithoutGravityReverse(Actor68 *arg0) {
    f32 temp;

    temp = Math_CosS(-arg0->unk30) * arg0->unk70;
    arg0->unk64 = Math_SinS(arg0->unk32) * temp;
    arg0->unk68 = Math_SinS(-arg0->unk30) * arg0->unk70;
    arg0->unk6C = Math_CosS(arg0->unk32) * temp;
}
