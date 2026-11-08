// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0161.h"

s32 func_800003F4(u8 *arg0, u8 *arg1) {
    u8 *player = M2C_FIELD(arg1, u8 **, 0x1CCC);

    if (M2C_FIELD(arg0, s32 *, 0x250) == 0) {
        return 0;
    }
    if ((M2C_FIELD(player, s32 *, 0xA74) & 0x20000000) && M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) {
        return 1;
    }
    return 0;
}
