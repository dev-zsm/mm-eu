// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Collider_ResetATBase(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 4) = 0;
    M2C_FIELD(arg1, u8 *, 0x10) = (u8) (M2C_FIELD(arg1, u8 *, 0x10) & 0xFFF9);
}
