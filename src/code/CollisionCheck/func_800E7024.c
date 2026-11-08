// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 CollisionCheck_SkipOC(struct Collider *col) {
    if (!(M2C_FIELD(col, u8 *, 0x12) & 1)) {
        return 1;
    }
    return 0;
}
