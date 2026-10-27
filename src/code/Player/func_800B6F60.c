// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Player_MountHorse(s32 arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg1, void **, 0x390) = arg2;
    M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) | 0x800000);
    M2C_FIELD(arg2, void **, 0x124) = arg1;
}
