// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0440.h"

void EnTest7_SpinAndSquishPlayer(EnTest7 *this, PlayState *play, f32 lerp) {
    f32 temp_f0;
    f32 temp_f2;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(play, u8 **, 0x1CCC);
    M2C_FIELD(temp_v0, s16 *, 0xBE) = (s16) (M2C_FIELD(temp_v0, s16 *, 0xBE) + 0x2EE0);
    temp_f0 = M2C_FIELD(this, f32 *, 0x1E90);
    M2C_FIELD(temp_v0, f32 *, 0x58) = (f32) (((0.0f - temp_f0) * lerp) + temp_f0);
    temp_f2 = M2C_FIELD(this, f32 *, 0x1E94);
    M2C_FIELD(temp_v0, f32 *, 0x60) = (f32) (((0.0f - temp_f2) * lerp) + temp_f2);
}
