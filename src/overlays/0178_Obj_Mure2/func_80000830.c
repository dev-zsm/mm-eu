// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0178.h"

void ObjMure2_Update(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(play, u8 *, 0x1F2C) == 0) {
        M2C_FIELD(thisx, f32 *, 0x17C) = 1.0f;
    } else {
        M2C_FIELD(thisx, f32 *, 0x17C) = 4.0f;
    }
    M2C_FIELD(thisx, M2C_UNK (**)(), 0x144)();
}
