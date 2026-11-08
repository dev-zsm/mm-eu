// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0643.h"

extern M2C_UNK D_80BFFD34;

void ObjDanpeilift_Wait(ObjDanpeilift *this, PlayState *play) {
    M2C_FIELD(this, s16 *, 0x186) = (s16) (M2C_FIELD(this, s16 *, 0x186) - 1);
    if (M2C_FIELD(this, s16 *, 0x186) <= 0) {
        M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80BFFD34;
        M2C_FIELD(this, f32 *, 0x70) = 0.0f;
    }
}
