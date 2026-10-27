// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void Collider_ResetOCBase(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0xC) = 0;
    M2C_FIELD(arg1, u8 *, 0x12) = (u8) (M2C_FIELD(arg1, u8 *, 0x12) & 0xFFFD);
    M2C_FIELD(arg1, u8 *, 0x13) = (u8) (M2C_FIELD(arg1, u8 *, 0x13) & 0xFFFE);
}
