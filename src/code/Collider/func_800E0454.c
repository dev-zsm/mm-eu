// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Collider_ResetOCBase(struct PlayState *play, struct Collider *col) {
    M2C_FIELD(col, s32 *, 0xC) = 0;
    M2C_FIELD(col, u8 *, 0x12) = (u8) (M2C_FIELD(col, u8 *, 0x12) & 0xFFFD);
    M2C_FIELD(col, u8 *, 0x13) = (u8) (M2C_FIELD(col, u8 *, 0x13) & 0xFFFE);
}
