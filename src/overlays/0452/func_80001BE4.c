#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0452.h"
f32 func_800B6B7C(u8 *a, u8 *b);

s32 func_80001BE4(u8 *a, u8 *play) {
    f32 d = func_800B6B7C(M2C_FIELD(play, u8 **, 0x1CCC), a + 8);

    if (d >= 150.0f) {
        return 1;
    }
    return 0;
}
