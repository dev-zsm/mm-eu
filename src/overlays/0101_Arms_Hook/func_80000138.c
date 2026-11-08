// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0101.h"

s32 ArmsHook_AttachToPlayer(ArmsHook *this, void *player) {
    M2C_FIELD(player, u8 **, 0x124) = this;
    M2C_FIELD(player, u8 **, 0x34C) = this;
    if (M2C_FIELD(this, s32 *, 0x124) != 0) {
        M2C_FIELD(this, s32 *, 0x124) = 0;
        M2C_FIELD(player, s32 *, 0x120) = 0;
        return 1;
    }
    return 0;
}
