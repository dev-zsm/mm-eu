// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Player_SetBButtonAmmo(struct PlayState *play, s32 ammo) {
    M2C_FIELD(play, s8 *, 0x1887C) = (s8) (ammo + 1);
    return 1;
}
