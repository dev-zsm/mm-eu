// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0472.h"

void func_800015E0(Actor *thisx, PlayState *play) {
    f32 temp_f0;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(play, u8 **, 0x1CCC);
    temp_f0 = M2C_FIELD(thisx, f32 *, 0x2C) + 70.0f;
    if (((M2C_FIELD(thisx, s16 *, 0x1C) & 0xFF) != 1) && (M2C_FIELD(temp_v0, f32 *, 0x2C) < temp_f0)) {
        M2C_FIELD(temp_v0, f32 *, 0x2C) = temp_f0;
    }
}
