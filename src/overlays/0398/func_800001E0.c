#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0398.h"
s32 func_800001E0(Actor *thisx, PlayState *play) {
    u8 *p = M2C_FIELD(play, u8 **, 0x1CE4);

    if (M2C_FIELD(thisx, s16 *, 0x1C) & 0x8000) {
        return 1;
    }
    for (; p != NULL; p = M2C_FIELD(p, u8 **, 0x12C)) {
        if (M2C_FIELD(p, s16 *, 0) == 0x1A4) {
            M2C_FIELD(thisx, u8 **, 0x120) = p;
            return 1;
        }
    }
    return 0;
}
