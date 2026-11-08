// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 Collider_ResetLineOC(struct PlayState *play, struct OcLine *line) {
    M2C_FIELD(line, u16 *, 0x18) = (u16) (M2C_FIELD(line, u16 *, 0x18) & 0xFFFE);
    return 1;
}
