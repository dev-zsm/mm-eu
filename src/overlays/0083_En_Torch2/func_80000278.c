// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0083.h"

extern M2C_UNK D_808A2B78;

void EnTorch2_UpdateIdle(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, u8 *, 0x190) == 4) {
        M2C_FIELD(thisx, M2C_UNK **, 0x138) = &D_808A2B78;
        M2C_FIELD(thisx, f32 *, 0x68) = 0.0f;
    }
}
